
/**
 * @file merge-intervals.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Merge Intervals using sort and merge algorithm.
 * @version 0.1
 * @date 2022-07-24
 * @note Algorithm -
 * 1. First sort the array on first index value so that we get all the
 * intervals' starting time in sequence.
 * 2. Start with taking starting point and last point of 0 index value as
 *    result's element start and end point.
 * 3. Start iteration through intervals -
 *  a) if last's end pointer is lesser than next interval's starting point
 *     that means end of overlapping , so add this start and end pointer to
 *     result and next start pointer will become this index value starting
 *     point.
 *  b) otherwise i.e. end pointer is greater than or equal to next interval's
 *     starting point that means overlapping continues.
 *  c) if overlapping breaks then start and end both pointer gets updated while
 *     if overlapping continues then only last pointer changes by higher value
 *     of current end pointer and this interval index 1 (end pointer value)
 *  d) end pointer to be updated as higher of both indexes value just to
 *     handle situation like - {1,4} and {2,3} should end up {1,4}
 *
 * TIME COMPLEXITY - O(NlogN)
 * SPACE COMPLEXITY - O(N)
 *
 * @copyright Copyright(c) 2022
 **/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {

    vector<vector<int>> mergedIntervals;

    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
      if (end >= intervals[i][0]) {
        end = max(end, intervals[i][1]);
      } else {
        mergedIntervals.push_back(vector<int>{start, end});
        start = intervals[i][0];
        end = intervals[i][1];
      }
    }

    mergedIntervals.push_back(vector<int>{start, end});

    return mergedIntervals;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int input;

    vector<vector<int>> vec;
    for (int i = 0; i < 10; i++) {
      vector<int> tmpVec;
      for (int j = 0; j < 2; j++) {
        tmpVec.push_back(rand() % 10);
      }
      vec.push_back(tmpVec);
    }

    Solution ob;
    vec = ob.merge(vec);

    for (int i = 0; i < vec.size(); i++) {
      for (int j = 0; j < vec[i].size(); j++) {
        cout << vec[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
  }