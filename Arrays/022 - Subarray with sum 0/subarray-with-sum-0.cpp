
/**
 * @file subarray-with-sum-0.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of positive and negative numbers. Find if there is a
 * subarray (of size at-least one) with 0 sum.
 * @version 0.1
 * @date 2022-08-30
 * @note Algorithm
 * 1. Declare a variable sum, to store the sum of prefix elements.
 * 2. Traverse the array and at each index, add the element into the sum and check if this sum exists earlier. If the sum exists, then return true.
 * 3. Also, insert every prefix sum into a map, so that later on it can be found whether the current sum is seen before or not.
 * 4. At the end return false, as no such subarray is found
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
  bool subArrayExists(int arr[], int n) {
    unordered_map<int, int> umap;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      if (sum == 0 || umap.find(sum) != umap.end()) {
        return 1;
      }
      umap.insert(make_pair(sum, 1));
    }

    return 0;
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
    int vec[10];

    for (int i = 0; i < 10; i++) {
      vec[i] = rand() % 10;
    }

    Solution s;
    bool result = s.subArrayExists(vec);

    if (result) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}