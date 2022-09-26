
/**
 * @file triplet-sum-in-array.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array arr of size n and an integer X. Find if there's a
 * triplet in the array which sums up to the given integer X.
 * @version 0.1
 * @date 2022-09-26
 *
 * TIME COMPLEXITY - O(N^2)
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // Function to find if there exists a triplet in the
  // array A[] which sums up to X.
  bool find3Numbers(int A[], int n, int X) {
    bool isThereATriplet = 0;
    sort(A, A + n);

    for (int i = 0; i < n; ++i) {
      int res = X - A[i];

      if (res < 0) {
        break;
      }

      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        if (A[j] + A[k] < res) {
          ++j;
        } else if (A[j] + A[k] > res) {
          --k;
        } else {
          isThereATriplet = 1;
          break;
        }
      }
    }

    return isThereATriplet;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;

    int A[n];

    for (int i = 0; i < 10; i++) {
      A[i] = rand() % 10;
    }

    Solution s;
    bool isTripletFound = s.find3Numbers(A, n, x);
    cout << isTripletFound << endl;
  }

  return 0;
}