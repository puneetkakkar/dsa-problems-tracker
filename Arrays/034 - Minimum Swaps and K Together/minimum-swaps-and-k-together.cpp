
/**
 * @file minimum-swaps-and-k-together.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array arr of n positive integers and a number k. One can
 * apply a swap operation on the array any number of times, i.e choose any two
 * index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of
 * swaps required to bring all the numbers less than or equal to k together,
 * i.e. make them a contiguous subarray.
 * @version 0.1
 * @date 2022-12-25
 * @note At first, the solution was thought to look around maximum length of
 * continguous array and then swap remaining elements along with them in order
 * to reduce or minimize the number of swaps. Later on, with the following
 * example it failed - N - 18, Arr - 2 1 7 9 5 6 4 8 7 4 9 10 7 8 4 3 2 1, K
 * - 6. Then, for this to solve we could solve via combination of sliding window
 * and two pointer technique. Following is the algorithm for this -
 * 1. Find count of all elements which are less than or equals to ‘k’.
 * 2. Let’s say the count is ‘cnt’ Using two pointer technique for window of
 * length ‘cnt’, each time keep track of how many elements in this range are
 * greater than ‘k’. Let’s say the total count is ‘bad’.
 * 3. Repeat step 2, for every window of length ‘cnt’ and take minimum of count
 * ‘bad’ among them.This will be the final answer.
 *
 * P.S - The motivation around this solution is the hint to have a contiguous
 * array at the end for all those elements <= k. Since, a continguous array
 * needs to be formed then we could go about checking every cell in a single
 * iteration via sliding window and two pointers approach and figure out the
 * minimum bad elements that are to be swapped to have contiguous array of good
 * elements.
 *
 * TIME COMPLEXITY - O(N)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSwap(int arr[], int n, int k) {

    // Find count of elements which are
    // less than equals to k
    int count = 0;
    for (int i = 0; i < n; ++i)
      if (arr[i] <= k)
        ++count;

    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
      if (arr[i] > k)
        ++bad;

    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {

      // Decrement count of previous window
      if (arr[i] > k)
        --bad;

      // Increment count of current window
      if (arr[j] > k)
        ++bad;

      // Update ans if count of 'bad'
      // is less in current window
      ans = min(ans, bad);
    }
    return ans;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int n;
    int k;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
      arr[i] = rand() % n;
    }

    cin >> k;

    Solution s;
    cout << s.minSwap(arr, n, k) << endl;
  }

  return 0;
}