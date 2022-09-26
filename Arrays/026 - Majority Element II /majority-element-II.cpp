/**
 * @file majority-element-II.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> result;
    int minNumberOfEle = floor(nums.size() / 3);

    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); ++i) {

      if (umap[nums[i]] != -1) {
        umap[nums[i]] += 1;
      }

      if (umap[nums[i]] > minNumberOfEle) {
        umap[nums[i]] = -1;
        result.push_back(nums[i]);
      }
    }

    return result;
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
    s.majorityElement(vec);
    s.displayVector(vec);
  }

  return 0;
}