
/**
 * @file three-way-partitioning.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an array of size n and a range [a, b]. The task is to partition
 * the array around the range such that array is divided into three parts.
 * 1) All elements smaller than a come first.
 * 2) All elements in range a to b come next.
 * 3) All elements greater than b appear in the end.
 * The individual elements of three sets can appear in any order. You are
 * required to return the modified array.
 * 
 * TIME COMPLEXITY - O(N)
 * SPACE COMPLEXITY - O(1)
 * 
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // Function to partition the array around the range such
  // that array is divided into three parts.
  void threeWayPartition(vector<int> &array, int a, int b) {
    int low = 0;
    int high = array.size() - 1;
    for (int i = 0; i <= high; ++i) {
      if (array[i] < a) {
        swap(array[i], array[low]);
        ++low;
      } else if (array[i] > b) {
        swap(array[i], array[high]);
        --high;
        --i;
      }
    }
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    vector<int> vec;

    cin >> n;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
      vec.push_back(rand() % n);
    }

    Solution s;
    s.threeWayPartition(vec, a, b);
  }

  return 0;
}