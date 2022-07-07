
/**
 * @file sort-012.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Sorting the 0,1,2 elements in an array without using sorting
 * algorithm, i.e dividing the array into 4 parts and keeping values greater
 * than high as 2's, values less than low as 0's, and keeping values within low
 * to mid as 1's, and keeping values greater than mid and less than high as
 * unknown.
 * @version 0.1
 * @date 2022-07-07
 *
 * @note Used a linear swapping to basically sort the array in-place.
 * 1. Keeping low, mid and high variables i.e low = all 0's are placed before
 * low, mid = all 1's placed between 0 and 2, and high = all 2's are placed
 * after high.
 * 2. Initialise low, and mid as 0, and high as n-1;
 * 3. Traverse the array from 0 to n-1, and handle following cases -
 *      a. If a[i] == 0, swap value with a[low] and increment low and mid.
 *         **Increment mid, so that it is started from where low ends rather than
 *         keeping it in the front.
 *      b. If a[i] == 1, only increment mid.
 *      c. If a[i] == 2, then swap last term value, decrease high, and decrement i, as that element is unprocessed currently
 * 4. Yay!! Array is sorted in place
 * 
 * TIME COMPLEXITY  - O(N) 
 * SPACE COMPLEXITY - O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sort012(int a[], int n) {
    int low = 0;
    int mid = 0;
    int high = n - 1;
    for (int i = 0; i <= high && mid <= high; ++i) {
      if (a[i] == 0) {
        swap(a[i], a[low]);
        ++low;
        ++mid;
      } else if (a[i] == 2) {
        swap(a[i], a[high]);
        --high;
        --i;
      } else {
        ++mid;
      }
    }
  }

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
};

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    Solution ob;
    ob.sort012(a, n);

    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }

    cout << endl;
  }
  return 0;
}