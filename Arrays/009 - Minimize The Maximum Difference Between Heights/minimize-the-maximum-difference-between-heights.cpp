
/**
 * @file minimize-the-maximum-difference-between-heights.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @note Algorithm - 
 * 1. Sort the array in ascending order.
 * 2. Initialize the variable result with the difference between the first and the last element of the array.
 * 3. Run a loop for one to the length of the array.
 * 4. Initialize the variable min to the minimum of (arr[0] +k, arr[i]-k).
 * 5. Initialize the variable max to the maximum of (arr[n-1] -k, arr[i-1]+k).
 * 6. Update the result with the minimum of the result and the difference between max and min.
 * 7. Return the result.
 * 
 * TIME COMPLEXITY - O(NlogN)
 * SPACE COMPLEXITY - O(1)
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        
        int minValue = arr[0];
        int maxValue = arr[n-1];
        int minDiff = maxValue - minValue;
        
        for(int i = 1; i < n; ++i) {
            if(arr[i] < k) {
                continue;
            };
            minValue = min(arr[0] + k, arr[i] - k);
            maxValue = max(arr[n-1] - k, arr[i - 1] + k);
            minDiff = min(minDiff, maxValue - minValue);
        }
        
        return minDiff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} 