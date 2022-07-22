
/**
 * @file merge-two-sorted-arrays-without-using-extra-space.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Merge 2 sorted arrays without extra space
 * @version 0.1
 * @date 2022-07-22
 * @note Algorithm
 * 1. Since both the arrays are sorted, compare last element of first array with
 * every element of second arrary.
 * 2. Swap the elements if arr1[n-1] > arr2[j].
 * 3. Incremnet j and decrement i.
 * 4. Now compare elements in a similar way until j < m or i >= 0.
 * 5. As a last step now sort both the arrays.
 * 6. Both arrays are sorted.
 *
 * TIME COMPLEXITY - O((n+m) log (n+m))
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
public:
  void merge(int arr1[], int arr2[], int n, int m) {
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m) {
      if (arr1[i] > arr2[j]) {
        swap(arr1[i], arr2[j]);
      }

      --i;
      ++j;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, i;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    for (i = 0; i < m; i++) {
      cin >> arr2[i];
    }
    Solution ob;
    ob.merge(arr1, arr2, n, m);
    for (i = 0; i < n; i++) {
      cout << arr1[i] << " ";
    }
    for (i = 0; i < m; i++) {
      cout << arr2[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends