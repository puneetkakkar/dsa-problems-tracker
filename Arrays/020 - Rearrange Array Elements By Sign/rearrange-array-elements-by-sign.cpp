
/**
 * @file rearrange-array-elements-by-sign.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief You are given a 0-indexed integer array nums of even length consisting
 * of an equal number of positive and negative integers. You should rearrange
 * the elements of nums such that the modified array follows the given
 * conditions:
 * 1. Every consecutive pair of integers have opposite signs.
 * 2. For all integers with the same sign, the order in which they were present in nums is preserved.
 * 3. The rearranged array begins with a positive integer.
 * @version 0.1
 * @date 2022-08-23
 * @note Algorithm
 * 1. Put separate signs in separate arrays.
 * 2. Using Two pointers push values accordingly to the main array
 * 3. Return the resultant array
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
  vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> positiveNums, negativeNums;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= 0) {
        positiveNums.push_back(nums[i]);
      } else {
        negativeNums.push_back(nums[i]);
      }
    }

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < positiveNums.size() && j < negativeNums.size()) {
      nums[k++] = positiveNums[i++];
      nums[k++] = negativeNums[j++];
    }

    return nums;
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
    vector<int> vec;

    for (int i = 0; i < 10; i++) {
      vec.push_back(rand() % 10);
    }

    Solution s;
    s.rearrangeArray(vec);
    s.displayVector(vec);
  }

  return 0;
}