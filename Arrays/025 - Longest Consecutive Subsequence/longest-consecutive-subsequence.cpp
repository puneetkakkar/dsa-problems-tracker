
/**
 * @file longest-consecutive-subsequence.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of positive integers. Find the length of the longest
 * sub-sequence such that elements in the subsequence are consecutive integers,
 * the consecutive numbers can be in any order.
 * @version 0.1
 * @date 2022-09-19
 *
 * TIME COMPLEXITY - O(N)
 * SPACE COMPLEXITY - O(N)
 * 
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // arr[] : the input array
  // N : size of the array arr[]

  // Function to return length of longest subsequence of consecutive integers.
  int findLongestConseqSubseq(int arr[], int N) {
    int maxEle = INT_MIN;
    int minEle = INT_MAX;
    unordered_map<int, bool> umap;
    for (int i = 0; i < N; ++i) {
      umap[arr[i]] = 1;
      if (maxEle < arr[i]) {
        maxEle = arr[i];
      }

      if (minEle > arr[i]) {
        minEle = arr[i];
      }
    }

    int i = minEle;
    int ans = 1;
    while (i < maxEle) {
      int currCount = 0;
      while (umap[i]) {
        ++currCount;
        ++i;
      }

      if (currCount > ans) {
        ans = currCount;
      }

      ++i;
    }

    return ans;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int arr[10];

    for (int i = 0; i < 10; i++) {
      vec.push_back(rand() % 10);
    }

    Solution s;
    s.findLongestConseqSubseq(arr, 10);
    s.displayVector(vec);
  }

  return 0;
}