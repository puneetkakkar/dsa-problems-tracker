
/**
 * @file count-inversions.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of integers. Find the Inversion Count in the array.
 * @version 0.1
 * @date 2022-07-24
 * @note Algorithm -
 * 1. The idea is similar to merge sort, divide the array into two equal or
 *    almost equal halves in each step until the base case is reached.
 * 2. Create a function merge that counts the number of inversions when two
 *    halves of the array are merged, create two indices i and j, i is the index
 *    for the first half, and j is an index of the second half. if a[i] is
 *    greater than a[j], then there are (mid – i) inversions. because left and
 *    right subarrays are sorted, so all the remaining elements in left-subarray
 *    (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
 * 3. Create a recursive function to divide the array into halves and find the
 *    answer by summing the number of inversions is the first half, the number
 *    of inversion in the second half and the number of inversions by merging
 *    the two.
 * 4. The base case of recursion is when there is only one element in the given
 *    half.
 * 5. Print the answer.
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
  long long inversions = 0;

  void inversionCountOnMerge(long long arr[], long long low, long long mid,
                             long long high) {

    long long lLen = mid - low + 1, rLen = high - mid;
    long long L[lLen], R[rLen];

    for (int i = 0; i < lLen; ++i) {
      L[i] = arr[low + i];
    }

    for (int i = 0; i < rLen; ++i) {
      R[i] = arr[mid + i + 1];
    }

    int index = low;
    int lIndex = 0;
    int rIndex = 0;

    while (lIndex < lLen && rIndex < rLen) {
      if (L[lIndex] > R[rIndex]) {
        arr[index] = R[rIndex];
        ++index;
        ++rIndex;
        inversions += lLen - lIndex;
      } else {
        arr[index] = L[lIndex];
        ++index;
        ++lIndex;
      }
    }

    while (lIndex < lLen) {
      arr[index] = L[lIndex];
      ++index;
      ++lIndex;
    }

    while (rIndex < rLen) {
      arr[index] = R[rIndex];
      ++index;
      ++rIndex;
    }
  }

  void countInversions(long long arr[], long long low, long long high) {
    if (low < high) {
      long long mid = low + (high - low) / 2;
      countInversions(arr, low, mid);
      countInversions(arr, mid + 1, high);
      inversionCountOnMerge(arr, low, mid, high);
    }
  }

  // arr[]: Input Array
  // N : Size of the Array arr[]
  // Function to count inversions in the array.
  void inversionCount(long long arr[], long long N) {
    countInversions(arr, 0, N - 1);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    long long arr[N];
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    Solution ob;
    ob.inversionCount(arr, N);

    cout << ob.inversions << endl;

    return 0;
  }
}