
/**
 * @file smallest-subarray-with-sum-greater-than-x.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of integers (A[])  and a number x, find the smallest
 * subarray with sum greater than the given value.
 * @version 0.1
 * @date 2022-10-09
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
  int smallestSubWithSum(int arr[], int n, int x) {
    int i = 0, j = 1;
    int ans = INT_MAX;
    int sum = arr[0];
    while (j <= n) {
      if (sum <= x) {
        sum += arr[j];
        j++;
      } else {
        ans = min(ans, j - i);
        sum -= arr[i];
        ++i;
      }
    }

    return ans < INT_MAX ? ans : 0;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;

    int arr[n];

    for (int i = 0; i < n; i++) {
      arr[i] = rand() % n;
    }

    Solution s;
    cout << s.smallestSubWithSum(arr, n, x) << endl;
  }

  return 0;
}