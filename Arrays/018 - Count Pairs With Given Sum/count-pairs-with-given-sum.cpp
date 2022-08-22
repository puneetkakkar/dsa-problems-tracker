/**
 * @file count-pairs-with-given-sum.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of N integers, and an integer K, find the number of
 * pairs of elements in the array whose sum is equal to K.
 * @version 0.1
 * @date 2022-08-22
 * @note Algorithm
 * 1. Create a map to store the frequency of each number in the array. (Single
 * traversal is required)
 * 2.	In the next traversal, for every element check if it can be combined
 * 		with any other element (other than itself!) to give the desired
 * 		sum. Increment the counter accordingly.
 * 3. After completion of the second traversal, we’d have twice the required
 * 		value stored in counter because every pair is counted two times.
 * 		Hence divide the count by 2 and return.
 *
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
  int getPairsCount(int arr[], int n, int k) {
    int pairsCount = 0;
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; ++i) {
      freqMap[arr[i]] += 1;
    }

    for (int i = 0; i < n; ++i) {
      int reqDiff = k - arr[i];

      if (reqDiff >= 0 && freqMap[reqDiff] > 0) {
        pairsCount += freqMap[reqDiff];
      }
    }

    if (k % 2 == 0 && freqMap[k / 2] >= 2) {
      pairsCount -= freqMap[k / 2];
    }

    return pairsCount /= 2;
  }

  void displayVector(vector<int> &vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
      cout << *it << " ";
    }

    cout << endl;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int n = 10;
    int k = 4;
    int arr[n];

    for (int i = 0; i < 10; i++) {
      arr[i] = rand() % 10;
    }

    Solution s;
    int pairsCount = s.getPairsCount(arr, n, k);
    cout << pairsCount << endl;
  }

  return 0;
}