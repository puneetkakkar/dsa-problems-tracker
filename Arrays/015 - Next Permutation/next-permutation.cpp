
/**
 * @file next-permutation.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Find the next lexicographically greater permutation of the given sequence.
 * @version 0.1
 * @date 2022-07-24
 * @note Algorithm - 
 * 1. Find the point a[i]<a[i+1] by iterating from last. This is our index1.
 * 2. If there is no breakpoint that means the array is in descending order. So, simply reverse the full array.
 * 3. Else again iterate from last and find the element that is great than a[index1]. Store it as index2.
 * 4. Swap the 2elements at index1 and index2.
 * 5. Finally reverse the array from index1+1, so that we get the minimum number. Which means the next permutation.
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
  void nextPermutation(vector<int> &nums) {

    int firstDecreasingIndex = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        firstDecreasingIndex = i;
        break;
      }
    }

    if (firstDecreasingIndex != -1) {
      int nextMaxNum = INT_MAX;
      int nextMaxNumIndex = -1;
      for (int j = firstDecreasingIndex + 1; j < nums.size(); ++j) {
        if (nums[j] > nums[firstDecreasingIndex] && nums[j] <= nextMaxNum) {
          nextMaxNum = nums[j];
          nextMaxNumIndex = j;
        }

        if (nums[j] < nums[firstDecreasingIndex]) {
          break;
        }
      }

      swap(nums[firstDecreasingIndex], nums[nextMaxNumIndex]);
    }

    reverse(nums.begin() + firstDecreasingIndex + 1, nums.end());
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int input;

    vector<int> nums;
    for (int i = 0; i < 10; i++) {
      nums.push_back(rand() % 10);
    }

    Solution ob;
    ob.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " ";
      cout << endl;
    }
    return 0;
  }