
/**
 * @file find-the maximum-and-minimum-element-in-an-array.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Found the maximum and minimum element in an array using linear
 * approach of replacing the value as max or min on basis of previous max or
 * mins in an array.
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n);

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];

    pair<ll, ll> pp = getMinMax(a, n);

    cout << pp.first << " " << pp.second << endl;
  }
  return 0;
}

pair<long long, long long> getMinMax(long long a[], int n) {

  pair<long long, long long> minMax(INT_MAX, INT_MIN);

  for (long long i = 0; i < n; ++i) {
    if (a[i] < minMax.first) {
      minMax.first = a[i];
    }

    if (a[i] > minMax.second) {
      minMax.second = a[i];
    }
  }

  return minMax;
}