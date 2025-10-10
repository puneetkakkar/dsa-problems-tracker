#!/usr/bin/env python3

import requests
import json
import argparse
from requests.exceptions import HTTPError, ConnectionError, Timeout, RequestException
import sys
import time
from datetime import datetime
import threading

# Load environment variables from file
from dotenv import load_dotenv
import os


# Specify the path to your environment file
load_dotenv("./.env")

# TOKEN AND IDS
NOTION_TOKEN = os.getenv("NOTION_TOKEN")
DATABASE_ID = os.getenv("DATABASE_ID")

# URL
NOTION_BASE_URL = "https://api.notion.com/"
LEETCODE_INFO_URL = "https://lcid.cc/info/"
LEETCODE_URL = "https://leetcode.com/problems/"

urlDatabase = f"{NOTION_BASE_URL}v1/databases/{DATABASE_ID}"
urlQueryPages = f"{NOTION_BASE_URL}v1/databases/{DATABASE_ID}/query"

headers = {
    "Authorization": "Bearer " + NOTION_TOKEN,
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28",
}

# Timer configuration
TIMER_FILE = ".active_timers.json"

# Expected time targets (in minutes) for senior engineer (5 YOE)
BASE_TIMES = {
    'Easy': 15,      # ≤15 minutes
    'Medium': 30,    # ≤30 minutes  
    'Hard': 45       # ≤45-60 minutes (using 45 as base)
}


def get_leetcode_info_by_id(id):
    try:
        leetcode_url = f"{LEETCODE_INFO_URL}{id}"
        resInfo = requests.get(leetcode_url, timeout=3)
        resInfo = resInfo.json()
        if "code" in resInfo:
            if resInfo["code"] != 200:
                raise RequestException(resInfo["message"])
            resInfo.raise_for_status()
        return resInfo
    except HTTPError as errh:
        sys.exit(errh)
    except ConnectionError as errc:
        sys.exit(errc)
    except Timeout as errt:
        sys.exit(errt)
    except RequestException as err:
        sys.exit(err)


def update_page(page_id: str, data: dict):
    url = f"https://api.notion.com/v1/pages/{page_id}"

    payload = {"properties": data}

    res = requests.patch(url, json=payload, headers=headers)
    
    # Check if the update was successful
    if res.status_code != 200:
        print(f"Error updating Notion page: {res.status_code}")
        print(f"Response: {res.text}")
        return None
    
    return res


def create_page(data: dict):
    create_url = "https://api.notion.com/v1/pages"

    payload = {
        "parent": {"type": "database_id", "database_id": DATABASE_ID},
        "properties": data,
    }

    res = requests.post(create_url, headers=headers, json=payload)
    
    # Check if the creation was successful
    if res.status_code != 200:
        print(f"Error creating Notion page: {res.status_code}")
        print(f"Response: {res.text}")
        return None
    
    return res


def present_in_database(leetcode_number):
    """
    If num_pages is None, get all pages, otherwise just the defined number.
    """
    filterProperties = {
        "filter": {"property": "Id", "number": {"equals": leetcode_number}}
    }
    url = f"https://api.notion.com/v1/databases/{DATABASE_ID}/query"

    response = requests.post(url, json=filterProperties, headers=headers)

    data = response.json()

    # Comment this out to dump all data to a file
    # with open('db.json', 'w', encoding='utf8') as f:
    #     json.dump(data, f, ensure_ascii=False, indent=4)

    results = data["results"]

    if len(results) == 0:
        return None

    return results[0]["id"]


def get_pages(num_pages=None):
    """
    If num_pages is None, get all pages, otherwise just the defined number.
    """

    url = f"https://api.notion.com/v1/databases/{DATABASE_ID}/query"

    get_all = num_pages is None
    page_size = 100 if get_all else num_pages

    payload = {"page_size": page_size}
    response = requests.post(url, json=payload, headers=headers)

    data = response.json()

    # Comment this out to dump all data to a file
    # with open('db.json', 'w', encoding='utf8') as f:
    #     json.dump(data, f, ensure_ascii=False, indent=4)

    results = data["results"]
    while data["has_more"] and get_all:
        payload = {"page_size": page_size, "start_cursor": data["next_cursor"]}
        url = f"https://api.notion.com/v1/databases/{DATABASE_ID}/query"
        response = requests.post(url, json=payload, headers=headers)
        data = response.json()
        results.extend(data["results"])

    return results


def calculate_expected_time(difficulty, acceptance_rate):
    """
    Calculate expected time based on difficulty and acceptance rate.
    Adjusts base time based on problem acceptance rate.
    """
    base_time = BASE_TIMES.get(difficulty, 30)  # Default to 30 if difficulty not found
    
    # Adjust based on acceptance rate
    if acceptance_rate > 50:
        # High acceptance - use lower target (easier problem)
        adjustment = -5
    elif acceptance_rate > 30:
        # Medium acceptance - use base target
        adjustment = 0
    else:
        # Low acceptance - use higher target (harder problem)
        adjustment = 10
    
    expected_time = max(5, base_time + adjustment)  # Minimum 5 minutes
    return expected_time


def load_active_timer():
    """Load active timer from JSON file."""
    try:
        if os.path.exists(TIMER_FILE):
            with open(TIMER_FILE, 'r') as f:
                return json.load(f)
    except (json.JSONDecodeError, FileNotFoundError):
        pass
    return None


def save_active_timer(timer_data):
    """Save active timer to JSON file."""
    try:
        with open(TIMER_FILE, 'w') as f:
            json.dump(timer_data, f, indent=2)
    except Exception as e:
        print(f"Error saving timer: {e}")


def clear_active_timer():
    """Clear active timer file."""
    try:
        if os.path.exists(TIMER_FILE):
            os.remove(TIMER_FILE)
    except Exception as e:
        print(f"Error clearing timer: {e}")


def start_timer(problem_number):
    """Start timer for a problem."""
    # Check if there's already an active timer
    active_timer = load_active_timer()
    if active_timer:
        print(f"Stopping previous timer for problem {active_timer['problem_number']}")
        clear_active_timer()
    
    # Get problem info
    leetcode_info = get_leetcode_info_by_id(problem_number)
    difficulty = leetcode_info["difficulty"]
    acceptance_rate = leetcode_info.get("acRate", 50)  # Default to 50% if not available
    
    # Calculate expected time
    expected_time = calculate_expected_time(difficulty, acceptance_rate)
    
    # Create timer data
    timer_data = {
        "problem_number": problem_number,
        "start_time": time.time(),
        "start_timestamp": datetime.now().isoformat(),
        "difficulty": difficulty,
        "acceptance_rate": acceptance_rate,
        "expected_time": expected_time,
        "problem_title": leetcode_info["title"]
    }
    
    # Save timer
    save_active_timer(timer_data)
    
    print(f"Timer started for problem {problem_number}: {leetcode_info['title']}")
    print(f"Difficulty: {difficulty}")
    print(f"Expected time: {expected_time} minutes")
    print(f"Acceptance rate: {acceptance_rate:.1f}%")
    print(f"Timer running... (Use 'python lc-tracker.py stop {problem_number}' to stop)")
    
    return timer_data


def stop_timer(problem_number):
    """Stop timer and calculate performance."""
    active_timer = load_active_timer()
    
    if not active_timer:
        print("No active timer found.")
        return None
    
    if active_timer["problem_number"] != problem_number:
        print(f"Active timer is for problem {active_timer['problem_number']}, not {problem_number}")
        return None
    
    # Calculate actual time
    start_time = active_timer["start_time"]
    actual_time = (time.time() - start_time) / 60  # Convert to minutes
    expected_time = active_timer["expected_time"]
    
    # Determine if too slow
    too_slow = actual_time > expected_time
    
    # Performance message
    time_diff = actual_time - expected_time
    if time_diff < -5:
        performance_msg = f"Excellent! {abs(time_diff):.1f} minutes faster than expected"
    elif time_diff < 0:
        performance_msg = f"Great! {abs(time_diff):.1f} minutes faster than expected"
    elif time_diff < 5:
        performance_msg = f"On time! {time_diff:.1f} minutes over expected"
    else:
        performance_msg = f"Slow! {time_diff:.1f} minutes over expected"
    
    print(f"Timer stopped for problem {problem_number}")
    print(f"Actual time: {actual_time:.1f} minutes")
    print(f"Expected time: {expected_time:.1f} minutes")
    print(f"Performance: {performance_msg}")
    
    # Clear timer
    clear_active_timer()
    
    return {
        "actual_time": actual_time,
        "expected_time": expected_time,
        "too_slow": too_slow,
        "performance_msg": performance_msg
    }


def show_timer_status():
    """Show current timer status."""
    active_timer = load_active_timer()
    
    if not active_timer:
        print("No active timer running.")
        return
    
    elapsed_time = (time.time() - active_timer["start_time"]) / 60
    expected_time = active_timer["expected_time"]
    
    print(f"Active timer for problem {active_timer['problem_number']}: {active_timer['problem_title']}")
    print(f"Elapsed time: {elapsed_time:.1f} minutes")
    print(f"Expected time: {expected_time:.1f} minutes")
    print(f"Time remaining: {max(0, expected_time - elapsed_time):.1f} minutes")


def main():
    parser = argparse.ArgumentParser(
        description="Generate leetcode question to fill up Notion for tracking of questions"
    )
    
    # Add subcommands
    subparsers = parser.add_subparsers(dest='command', help='Available commands')
    
    # Start command
    start_parser = subparsers.add_parser('start', help='Start timer for a problem')
    start_parser.add_argument('leetcode_number', type=int, help='Leetcode question number')
    
    # Stop command
    stop_parser = subparsers.add_parser('stop', help='Stop timer for a problem')
    stop_parser.add_argument('leetcode_number', type=int, help='Leetcode question number')
    stop_parser.add_argument("-b", "--bookmark", action="store_true", help="Bookmark a question")
    stop_parser.add_argument("-c", "--comment", nargs="?", default="", help="Optional comment for the question")
    
    # Status command
    status_parser = subparsers.add_parser('status', help='Show current timer status')
    
    # Legacy command (backward compatibility)
    legacy_parser = subparsers.add_parser('legacy', help='Legacy mode - add/update problem without timer')
    legacy_parser.add_argument('leetcode_number', type=int, help='Leetcode question number')
    legacy_parser.add_argument("-b", "--bookmark", action="store_true", help="Bookmark a question")
    legacy_parser.add_argument("-c", "--comment", nargs="?", default="", help="Optional comment for the question")
    
    args = parser.parse_args()
    
    # Handle different commands
    if args.command == 'start':
        start_timer(args.leetcode_number)
        
    elif args.command == 'stop':
        # Stop timer and get performance data
        timer_result = stop_timer(args.leetcode_number)
        
        if timer_result:
            # Get problem info for Notion update
            leet_code = get_leetcode_info_by_id(args.leetcode_number)
            difficulty = leet_code["difficulty"]
            name = leet_code["title"]
            nameForURL = leet_code["titleSlug"]
            topic_tags = [{'name': tag['name']} for tag in leet_code['topicTags']]
            
            page_id = present_in_database(args.leetcode_number)
            
            # Prepare timing data for Notion
            timing_data = {
                "Expected Time": {
                    "rich_text": [{"text": {"content": f"{timer_result['expected_time']:.1f} min"}}]
                },
                "Actual Time": {
                    "rich_text": [{"text": {"content": f"{timer_result['actual_time']:.1f} min"}}]
                },
                "Too Slow?": {"checkbox": timer_result["too_slow"]}
            }
            
            if page_id is not None:
                # Update existing page
                updateData = {
                    "Id": {"number": args.leetcode_number},
                    "Bookmark": {"checkbox": args.bookmark},
                    **timing_data
                }
                
                if args.comment != "":
                    updateData["Notes"] = {
                        "rich_text": [{"text": {"content": args.comment}}]
                    }
                
                update_page(page_id, updateData)
                print(f"Question {args.leetcode_number} updated with timing data in Notion database.")
            else:
                # Create new page
                data = {
                    "Name": {
                        "title": [{"text": {"content": name}}]
                    },
                    "Difficulty": {
                        "select": {"name": difficulty}
                    },
                    "Topics": {
                        "multi_select": topic_tags,
                    },
                    "Link": {"url": f"{LEETCODE_URL}{nameForURL}"},
                    "Id": {"number": args.leetcode_number},
                    "Notes": {
                        "rich_text": [{"text": {"content": args.comment}}]
                    },
                    "Bookmark": {"checkbox": args.bookmark},
                    **timing_data
                }
                
                create_page(data)
                print(f"Question {args.leetcode_number} added with timing data to Notion database.")
                
    elif args.command == 'status':
        show_timer_status()
        
    elif args.command == 'legacy':
        # Original functionality for backward compatibility
        leetcode_number_input_by_user = args.leetcode_number
        leetcode_bookmark_input_by_user = args.bookmark
        leetcode_comment_input_by_user = args.comment

        leet_code = get_leetcode_info_by_id(leetcode_number_input_by_user)

        difficulty = leet_code["difficulty"]
        name = leet_code["title"]
        nameForURL = leet_code["titleSlug"]
        topic_tags = [{'name': tag['name']} for tag in leet_code['topicTags']]

        page_id = present_in_database(leetcode_number_input_by_user)

        if page_id is not None:
            if leetcode_comment_input_by_user != "":
                updateData = {
                    "Id": {"number": leetcode_number_input_by_user},
                    "Notes": {
                        "rich_text": [{"text": {"content": leetcode_comment_input_by_user}}]
                    },
                    "Bookmark": {"checkbox": leetcode_bookmark_input_by_user}
                }
            else:
                updateData = {
                    "Id": {"number": leetcode_number_input_by_user},
                    "Bookmark": {"checkbox": leetcode_bookmark_input_by_user}
                }

            update_page(page_id, updateData)
            print(f"Question {leetcode_number_input_by_user} updated (Last Done) in the Notion database.")
        else:
            data = {
                "Name": {
                    "title": [
                        {
                            "text": {
                                "content": name,
                            },
                        }
                    ]
                },
                "Difficulty": {
                    "select": {
                        "name": difficulty,
                    }
                },
                "Topics": {
                    "multi_select": topic_tags,
                },
                "Link": {"url": f"{LEETCODE_URL}{nameForURL}"},
                "Id": {"number": leetcode_number_input_by_user},
                "Notes": {
                    "rich_text": [{"text": {"content": leetcode_comment_input_by_user}}]
                },
                "Bookmark": {"checkbox": leetcode_bookmark_input_by_user}
            }

            create_page(data)
            print(f"Question {leetcode_number_input_by_user} added to the Notion database.")
    
    else:
        # No command provided, show help
        parser.print_help()


if __name__ == "__main__":
    main()
