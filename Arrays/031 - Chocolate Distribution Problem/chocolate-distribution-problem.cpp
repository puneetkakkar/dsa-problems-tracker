
/**
 * @file chocolate-distribution-problem.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array A[ ] of positive integers of size N, where each value
 *        represents the number of chocolates in a packet. Each packet can have
 * a variable number of chocolates. There are M students, the task is to
 * distribute chocolate packets among M students such that :
 *        1. Each student gets exactly one packet.
 *        2. The difference between maximum number of chocolates given to a
 * student and minimum number of chocolates given to a student is minimum.
 * @version 0.1
 * @date 2022-10-09
 * @note Algorithm -
 * 1. Find the subarray of size m such that the difference between the last
 *    (maximum in case of sorted) and first (minimum in case of sorted) elements
 *    of the subarray is minimum.
 * 2. We will run a loop from 0 to (n-m), where n is the size of the given array
 *    and m is the size of the subarray.
 * 3. We will calculate the maximum difference with the subarray and store it in
 *    diff = arr[highest index] - arr[lowest index]
 * 4. Whenever we get a diff less than the min_diff, we will update the min_diff
 *    with diff.
 *
 * TIME COMPLEXITY - O(NLogN)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long findMinDiff(vector<long long> a, long long n, long long m) {
    if (m == 1)
      return 0;

    sort(a.begin(), a.end());

    long long i = 0, j = m - 1;
    long long ans = INT_MAX;

    while (j < a.size() && i < j) {
      ans = min(ans, a[j] - a[i]);
      j++;
      i++;
    }

    return ans;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    vector<long long> vec;

    for (int i = 0; i < 10; i++) {
      vec.push_back(rand() % 10);
    }

    Solution s;
    long long ans = s.findMinDiff(vec, 10, 5);

    cout << ans << endl;
  }

  return 0;
}