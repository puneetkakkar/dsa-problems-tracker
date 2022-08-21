/**
 * @file best-time-to-buy-and-sell-stock.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Maximize profit by shoosing to buy the stock at a given day and then
 * selling it on a different day in the future
 * @version 0.1
 * @date 2022-08-22
 * @note Follow Kadane's Algorithm
 * 1. Find minPrice in one-way and maxProfit comparing every element in a single pass.
 * 2. When the maxProfit is max of prices[i] - minPrice and maxProfit, update maxProfit to be prices[i] - minPrice.
 * 3. Return maxProfit.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      }

      if (maxProfit < (prices[i] - minPrice)) {
        maxProfit = prices[i] - minPrice;
      }
    }

    return maxProfit;
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
		int maxProfit = s.maxProfit(vec);
    cout << maxProfit << endl;
  }

  return 0;
}