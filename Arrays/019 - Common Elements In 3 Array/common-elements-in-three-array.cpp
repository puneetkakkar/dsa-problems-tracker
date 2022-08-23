#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> commonElements(int A[], int B[], int C[], int n1, int n2,
                             int n3) {
    vector<int> result;
    unordered_map<int, int> m;

    for (int i = 0; i < n1; ++i) {
      if (m[A[i]] < 1) {
        m[A[i]]++;
      }
    }

    for (int i = 0; i < n2; ++i) {
      if (m[B[i]] == 1) {
        m[B[i]]++;
      }
    }

    for (int i = 0; i < n3; ++i) {
      if (m[C[i]] == 2) {
        m[C[i]]++;
        result.push_back(C[i]);
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
    int n1 = 10;
    int n2 = 15;
    int n3 = 12;

    int A[n1], B[n2], C[n3];

    for (int i = 0; i < n1; i++) {
      A[i] = rand() % 10;
    }

    for (int i = 0; i < n2; i++) {
      B[i] = rand() % 10;
    }

    for (int i = 0; i < n3; i++) {
      C[i] = rand() % 10;
    }

    Solution s;
    vector<int> result = s.commonElements(A, B, C, n1, n2, n3);
    s.displayVector(result);
  }

  return 0;
}