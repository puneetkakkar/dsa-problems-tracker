
/**
 * @file array-subset-of-another-array.cpp
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
  string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> umap;
    string result = "Yes";

    for (int i = 0; i < n; ++i) {
      umap[a1[i]]++;
    }

    for (int i = 0; i < m; ++i) {
      if (!umap[a2[i]]) {
        result = "No";
        break;
      } else {
        umap[a2[i]]--;
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
    int n, m;
    cin >> n >> m;

    int a1[n], a2[m];

    for (int i = 0; i < n; i++) {
      a1[i] = rand() % 10;
    }

    for (int i = 0; i < m; i++) {
      a2[i] = rand() % 10;
    }

    Solution s;
    string result = s.isSubset(a1, a2, n, m);
    cout << result << endl;
  }

  return 0;
}
