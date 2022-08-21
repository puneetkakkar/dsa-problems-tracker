/**
 * @file template.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Question Description
 * @version 0.1
 * @date 2022-08-22
 * @note Algorithm
 * 
 * 
 * TIME COMPLEXITY - O(N)
 * SPACE COMPLEXITY - O(1)
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void runSample(vector<int> &vec) {
    // Write your code here
  }

  void displayVector(vector<int> &vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
      cout << *it << " ";
    }

    cout << endl;
  }
};

int main() {
  srand(static_cast<unsigned int>(time(nullptr)));

  int t;
  cin >> t;
  while (t--) {
    vector<int> vec;

    for (int i = 0; i < 10; i++) {
      vec.push_back(rand() % 10);
    }

    Solution s;
    s.runSample(vec);
    s.displayVector(vec);
  }

  return 0;
}