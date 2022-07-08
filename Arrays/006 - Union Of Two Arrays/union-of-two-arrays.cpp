
/**
 * @file union-of-two-arrays.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Union of two arrays i.e a set containing distinct elements from both
 * the arrays. If there are repetitions, then only one occurrence of element
 * should be printed in the union.
 * @version 0.1
 * @date 2022-07-08
 *
 * @note Union of the two arrays.
 * 1. Intialize a set.
 * 2. Insert elements in set from first array.
 * 3. Insert elements in the same set from second array.
 * 4. Return the total size of the set.
 * 
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

// User function template in C++

class Solution {
public:
  // Function to return the count of number of elements in union of two arrays.
  int doUnion(int a[], int n, int b[], int m) {
    set<int> s1;

    for (int i = 0; i < n; ++i) {
      s1.insert(a[i]);
    }

    for (int j = 0; j < m; ++j) {
      s1.insert(b[j]);
    }

    return s1.size();
  }
};

int main() {

  int t;
  cin >> t;

  while (t--) {

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    for (int i = 0; i < n; i++)
      cin >> a[i];

    for (int i = 0; i < m; i++)
      cin >> b[i];
    Solution ob;
    cout << ob.doUnion(a, n, b, m) << endl;
  }

  return 0;
}