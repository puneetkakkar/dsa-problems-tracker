
/**
 * @file rotate-an-array-by-one.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Rotate an Array in place
 * @version 0.1
 * @date 2022-07-08
 *
 * @note Rotating an array in place -
 * 1. Loop the array, and swap array position with the last position always
 * keeping last position fixed. 
 * 2. Yay!! Array is rotated.
 *
 * TIME COMPLEXITY  - O(N) 
 * SPACE COMPLEXITY - O(1)
 * 
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n], i;
    for (i = 0; i < n; i++)
      scanf("%d", &a[i]);
    rotate(a, n);
    for (i = 0; i < n; i++)
      printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}

void rotate(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    swap(arr[i], arr[n - 1]);
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}