// Initial function template for C++

/**
 * @file kth-smallest-element.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Algorithm uses a Quick Select Algorithm which is basically a tweaked
 * algorithm of Quick Sort Partition Algorithm and helps in knowing the kth
 * smallest/largest element in an array.
 * @version 0.1
 * @date 2022-07-05
 * 
 * @note In Quick Select Algorithm, the partition happens the same way it
 * happens in the Quick Sort, i.e
 * 1. Element is picked up as a pivot
 * 2. Keeping 2-pointer, i & j
 * 3. Swap values if arr[i] <= arr[pivot], increment j
 * 4. values till j would be smaller than pivot on the left and bigger than the
 * pivot on the right
 * 5. Recur only on the one side where kth smallest element is located as
 * opposed to recurring both sides during Quick Sort partitioning 6.
 * 6. If kth smallest element is found at pivot index, you have found your
 * kth-smallest element.
 * 
 * TIME COMPLEXITY  - O(N)
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
  // arr : given array
  // l : starting index of the array i.e 0
  // r : ending index of the array i.e size-1
  // k : find kth smallest element and return using this function
  int kthSmallest(int arr[], int l, int r, int k) {
    int pi = randomPartition(arr, l, r);

    // perform a comparision between `k` and pivot index `pi` by subtracting `1`
    // from `k` i.e k-1 as `k` is expected to be 1-index and pi is expected as
    // 0-index
    if (k - 1 == pi)
      return arr[pi];
    else if (k - 1 < pi)
      return kthSmallest(arr, l, pi - 1, k);
    else
      return kthSmallest(arr, pi + 1, r, k);
  }

  int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int rpivot = rand() % n;

    // add `l` to `rpivot` in array indexing, so that it starts
    // dynamically instead of starting it from `0`
    swap(arr[l + rpivot], arr[r]);

    return partition(arr, l, r);
  }

  int partition(int arr[], int l, int r) {
    int j = l;
    for (int i = l; i < r; i++) {
      if (arr[i] <= arr[r]) {
        swap(arr[i], arr[j]);
        ++j;
      }
    }

    swap(arr[j], arr[r]);

    return j;
  }

  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
};

int main() {
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int number_of_elements;
    cin >> number_of_elements;
    int a[number_of_elements];

    for (int i = 0; i < number_of_elements; i++)
      cin >> a[i];

    int k;
    cin >> k;
    Solution ob;
    cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
  }
  return 0;
}