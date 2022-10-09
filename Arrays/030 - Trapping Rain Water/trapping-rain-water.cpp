
/**
 * @file trapping-rain-water.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array arr[] of N non-negative integers representing the
 * height of blocks. If width of each block is 1, compute how much water can be
 * trapped between the blocks during the rainy season.
 * @version 0.1
 * @date 2022-10-09
 * @note Algorithm
 * 1. Create two arrays left[] and right[] of size N. Create a variable (say
 * max) to store the maximum found till a certain index during traversal.
 * 2. Run one loop from start to end:
 *  2.1 In each iteration update max and also assign left[i] = max.
 * 3. Run another loop from end to start:
 *  3.1 In each iteration update max found till now and also assign right[i] =
 * max.
 * 4. Traverse the array from start to end.
 *  4.1 The amount of water that will be stored in this column is min(left[i],
 * right[i]) - array[i] 4.2 Add this value to the total amount of water stored
 * 5. Print the total amount of water stored.
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

  // Function to find the trapped water between the blocks.
public:
  long long trappingWater(int arr[], int n) {
    vector<long long> leftVec;
    vector<long long> rightVec;
    long long ans = 0;

    long long leftMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
      leftMax = max(leftMax, (long long)arr[i]);
      leftVec.push_back(leftMax);
    }

    long long rightMax = INT_MIN;
    for (int i = n - 1; i >= 0; --i) {
      rightMax = max(rightMax, (long long)arr[i]);
      rightVec.push_back(rightMax);
    }

    reverse(rightVec.begin(), rightVec.end());

    for (int i = 0; i < n; ++i) {
      ans += min(leftVec[i], rightVec[i]) - arr[i];
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

    cin >> n;

    int a[n];

    for (int i = 0; i < 10; i++) {
      a[i] = rand() % 10;
    }

    Solution s;
    cout << s.trappingWater(a, n) << endl;
  }

  return 0;
}
