
/**
 * @file move-negative-to-one-side.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Moving all the negative elements towards one-side following a two
 * pointer approach
 * @version 0.1
 * @date 2022-07-08
 *
 * @note Moved all the negative elements towards the one side by following two
 * pointer approach -
 * 1. Assign two pointers, negative pointer as 0 i.e all negative values occur
 * before this pointer, and positive pointer as n-1 i.e all positive values
 * occur after this pointer.
 * 2. Loop until negative pointer <= positive pointer
 * 3. If a negative value occurs then increment the negative pointer
 * 4. If a positive value occurs then swap values with value at positive
 * pointer and decrement the positive pointer.
 * 5. Yay!! all negative elements moved to left side/one side.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void moveNegativesToOneSide(int a[], int n) {
    int negativePointer = 0;
    int positivePointer = n - 1;
    while (negativePointer <= positivePointer) {
      if (a[negativePointer] < 0) {
        ++negativePointer;
      } else {
        swap(a[negativePointer], a[positivePointer]);
        --positivePointer;
      }
    }
  }

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
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
    ob.moveNegativesToOneSide(a, n);
    ob.displayArray(a, n);
    cout << endl;
  }
  return 0;
}