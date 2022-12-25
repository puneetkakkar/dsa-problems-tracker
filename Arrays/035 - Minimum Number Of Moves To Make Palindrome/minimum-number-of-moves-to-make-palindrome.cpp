/**
 * @file minimum-number-of-moves-to-make-palindrome.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief You are given a string s consisting only of lowercase English letters.
 * In one move, you can select any two adjacent characters of s and swap
 * them. Return the minimum number of moves needed to make s a palindrome.
 * Note that the input will be generated such that s can always be converted to
 * a palindrome.
 * @version 0.1
 * @date 2022-12-25
 * @note
 * Intuition 1: It is always cheaper to keep either the left or right
 * character in place, as opposed to moving some other character to the left and
 * right.
 * Intuition 2: It actually does not matter whether we keep the left or right
 * character. Consider this example: "eleltt" -> "leeltt" -> "leetlt" ->
 * "leettl" -> "letetl" -> "lettel". As it would normally take the required
 * number of moves before becoming a palindrome.
 * Intuition 3: Somewhat based on Intuition 2 i.e how do we know that there
 * isn't some other character that is not in the first or last position that is
 * optimal? Since, the number of moves won't change much, so matching the
 * character later must therefore be better than swapping the character towardds
 * l, and r.
 * Problem - What about the odd one out character? for ex: "abbaa"
 * Ans - When traversing and checking the minimum diff from both ends, the
 * traversal itself gets either side diff to be lower as the diff for odd one
 * out would be maximum within [l,r] for that traversal, which automatically
 * swaps the odd element to its right place. Eg: "abbaa" -> "abbaa" -> "ababa"
 * Following is the algorithm used -
 * if s[left] and s[right] are not equal:
 * 1. From j = right, check whether there is an element equal to s[left].
 *    Decrement j until an equal element is not found
 * 2. Similarly, i = left, check whether there is an element equal to s[right].
 *    Increment i until an equal element is not found
 * 3. Now we need to greedily decide to either move element at left to element
 *    at i, or element at right to element at j
 * 4. Calculate the cost for both possibilities, (i - left and right - j)
 * 5. Choose the minimum and move those elements by adjacent swaps
 *
 * TIME COMPLEXITY - O(N^2)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int n = s.size();
    int res = 0, left = 0, right = n - 1;

    while (left < right) {
      int pright = right;
      while (left < pright && s[left] != s[pright]) {
        --pright;
      }

      int diff1 = right - pright;

      int pleft = left;
      while (right > pleft && s[right] != s[pleft]) {
        ++pleft;
      }

      int diff2 = pleft - left;

      if (diff1 < diff2) {
        while (pright != right) {
          swap(s[pright], s[pright + 1]);
          ++pright;
        }
      } else {
        while (pleft != left) {
          swap(s[pleft], s[pleft - 1]);
          --pleft;
        }
      }

      res += min(diff1, diff2);
      ++left;
      --right;
    }

    return res;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    string str;

    cin >> str;

    Solution s;
    cout << s.minMovesToMakePalindrome(str) << endl;
  }

  return 0;
}