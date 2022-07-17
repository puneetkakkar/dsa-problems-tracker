
/**
 * @file find-duplicate-in-an-array-of-N+1-integers.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Find duplicate number in an array using two pointer method i.e fast
 * pointer and slow pointer
 * @version 0.1
 * @date 2022-07-17
 * @note Implemented Floyd's Algorithm to solve the problem. Every number would
 * be leading to another number within [1,n] and later on forming a loop.
 * Firstly, a loop is identified that will be the element just before the loop
 * starting point, then the starting of the loop is identified which is the
 * duplicate element.
 *
 * TIME COMPLEXITY - O(n)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = 0;
    int fast = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    int nextSlow = 0;
    while (nextSlow != slow) {
      nextSlow = nums[nextSlow];
      slow = nums[slow];
    }

    return slow;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int input;
    vector<int> vec;

    while (cin >> input) {
      vec.push_back(input);
    }

    Solution ob;
    auto ans = ob.findDuplicate(vec);
    cout << ans << "\n";
  }
  return 0;
}