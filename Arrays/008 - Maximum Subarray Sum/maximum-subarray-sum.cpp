
/**
 * @file maximum-subarray-sum.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief The simple idea of Kadane's algorithm is to look for all positive
 * contiguous segments of the array (curr_sum is used for this). And keep track
 * of the maximum sum contiguous segment among all positive segments (max_sum is
 * used for this). Each time we get a positive-sum compare it with max_sum
 * and update max_sum if it is greater than max_sum
 * @version 0.1
 * @date 2022-07-09
 *
 * @note - Apply Kadane's Algorithm
 *
 * 1. Initialize:
 *      max_sum = INT_MIN
 *      curr_sum = 0
 * 2. Loop for each element of the array
 *      (a) curr_sum = curr_sum + a[i]
 *      (b) if(max_sum < curr_sum)
 *          max_sum = curr_sum
 *      (c) if(curr_sum < 0)
 *      curr_sum = 0
 * 3. return max_sum
 * 
 * TIME COMPPLEXITY - O(N)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // arr: input array
  // n: size of array
  // Function to find the sum of contiguous subarray with maximum sum.
  long long maxSubarraySum(int arr[], int n) {

    long long maxSum = INT_MIN;
    long long currSum = 0;
    for (long long i = 0; i < n; ++i) {
      currSum = currSum + arr[i];
      if (currSum > maxSum) {
        maxSum = currSum;
      }

      if (currSum < 0) {
        currSum = 0;
      }
    }

    return maxSum;
  }
};

int main() {
  int t, n;

  cin >> t;   // input testcases
  while (t--) // while testcases exist
  {

    cin >> n; // input size of array

    int a[n];

    for (int i = 0; i < n; i++)
      cin >> a[i]; // inputting elements of array

    Solution ob;

    cout << ob.maxSubarraySum(a, n) << endl;
  }
}