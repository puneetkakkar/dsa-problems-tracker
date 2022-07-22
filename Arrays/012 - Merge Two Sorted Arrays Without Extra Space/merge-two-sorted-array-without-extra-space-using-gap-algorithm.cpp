/**
 * @file merge-two-sorted-array-without-extra-space-using-gap-algorithm.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Merge 2 sorted arrays without extra space using Gap Algorithm
 * @version 0.1
 * @date 2022-07-22
 * @note Solved using gap algorithm which is a modified shell sort.
 * 1. Calculate gap within the arrays to compare values and loop until gap > 0
 * and reduce gap while looping every time.
 * 2. Initialize two pointers i and j for both arrays.
 * 3. Compare elements in the first array with the gap decided until it reaches
 * end of the first array and swap elements if a[i] > a[i+gap].
 * 4. After that move gap to second array i.e i iterator is in first array and j
 * iterator is in second array and start from gap-n index rather than -th index.
 * 5. Then if second array is longer and j<m then loop for second array using
 * both iterators and swap value if a[j] > a[j+gap]
 * 6. Both arrays are sorted
 *
 * TIME COMPLEXITY - O(NlogN)
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
    int gap = nextGap(n + m);
    while (gap) {
      int i = 0;
      int j = 0;

      for (i = 0; i + gap < n; ++i) {
        if (arr1[i] > arr1[i + gap]) {
          swap(arr1[i], arr1[i + gap]);
        }
      }

      for (j = gap > n ? gap - n : 0; j < m && i < n; ++j, ++i) {
        if (arr1[i] > arr2[j]) {
          swap(arr1[i], arr2[j]);
        }
      }

      if (j < m) {
        for (j = 0; j + gap < m; ++j) {
          if (arr2[j] > arr2[j + gap]) {
            swap(arr2[j], arr2[j + gap]);
          }
        }
      }

      gap = nextGap(gap);
    }
  }

  int nextGap(int gap) {
    if (gap <= 1) {
      return 0;
    }

    return (gap / 2) + (gap % 2);
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