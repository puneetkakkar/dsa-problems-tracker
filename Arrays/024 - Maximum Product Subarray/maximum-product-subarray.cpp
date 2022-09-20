
/**
 * @file maximum-product-subarray.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array Arr[] that contains N integers (may be positive,
 * negative or zero). Find the product of the maximum product subarray.
 * @version 0.1
 * @date 2022-09-20
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
  // Function to find maximum product subarray
  long long maxProduct(vector<int> arr, int n) {
    long long maxProd = arr[0];
    long long minProd = arr[0];
    long long res = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
      long long currMax = arr[i] * maxProd;
      long long currMin = arr[i] * minProd;
      maxProd = max(arr[i] * 1ll, max(currMax, currMin));
      minProd = min(arr[i] * 1ll, min(currMax, currMin));

      res = max(res, maxProd);
    }

    return res;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++) {
      vec.push_back(rand() % 10);
    }

    Solution ob;
    long long result = ob.maxProduct(vec, n);
    cout << result << endl;
  }
  return 0;
}