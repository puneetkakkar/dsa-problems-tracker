
/**
 * @file rearrange-array-elements-by-sign-in-constant-space.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of positive and negative numbers, arrange them in an
 * alternate fashion such that every positive number is followed by a negative
 * and vice-versa maintaining the order of appearance. The number of positive
 * and negative numbers need not be equal. If there are more positive numbers
 * they appear at the end of the array. If there are more negative numbers, they
 * too appear at the end of the array.
 * @version 0.1
 * @date 2022-08-23
 * @note Algorithm
 * 1. We will iterate over the array
 * 2. If outofplace is -1, we will check if the current index is out of place.
 * 3. If the current index is out of place we will update the outofplace with
 *    the index value.
 * 4. Else we will keep the value as it is.
 * 5. If the outofplace is not -1, we will search for the next index which has a
 *    different sign than that of the value that is present in outofplace
 *    position.
 * 6. Now we will pass this two positions to right rotate our array.
 * 7. Update the value of outofplace by 2 unit.
 *
 * 
 * TIME COMPLEXITY - O(N*N), as we are using a loop to traverse N times and
 * calling function to right rotate each time which will cost O (N).
 * SPACE COMPLEXITY - O(1)
 * 
 * 
 * @copyright Copyright (c) 2022
 *
 */

#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur) {
  char tmp = arr[cur];
  for (int i = cur; i > outofplace; i--)
    arr[i] = arr[i - 1];
  arr[outofplace] = tmp;
}

void rearrange(int arr[], int n) {
  int outofplace = -1;

  for (int index = 0; index < n; index++) {
    if (outofplace >= 0) {
      // find the item which must be moved into the
      // out-of-place entry if out-of-place entry is
      // positive and current entry is negative OR if
      // out-of-place entry is negative and current
      // entry is negative then right rotate
      //
      // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
      // -5...]
      //      ^                          ^
      //      |                          |
      //     outofplace      -->      outofplace
      //
      if (((arr[index] >= 0) && (arr[outofplace] < 0)) ||
          ((arr[index] < 0) && (arr[outofplace] >= 0))) {
        rightrotate(arr, n, outofplace, index);

        // the new out-of-place entry is now 2 steps
        // ahead
        if (index - outofplace >= 2)
          outofplace = outofplace + 2;
        else
          outofplace = -1;
      }
    }

    // if no entry has been flagged out-of-place
    if (outofplace == -1) {
      // check if current entry is out-of-place
      if (((arr[index] >= 0) && (!(index & 0x01))) ||
          ((arr[index] < 0) && (index & 0x01))) {
        outofplace = index;
      }
    }
  }
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver code
int main() {

  int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Given array is \n";
  printArray(arr, n);

  rearrange(arr, n);

  cout << "Rearranged array is \n";
  printArray(arr, n);

  return 0;
}