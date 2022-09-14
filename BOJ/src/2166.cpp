#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n;
  cin >> n;
  vector<pair<long, long>> point;
  for (int i = 0; i < n; ++i) {
    pair<long long, long long> a;
    cin >> a.first >> a.second;
    point.push_back(a);
  }
  point.push_back(point[0]);

  long long left_to_right = 0;
  long long right_to_left = 0;

  for (int i = 0; i < n; ++i) {
    left_to_right += point[i].first * point[i + 1].second;
    right_to_left += point[i + 1].first * point[i].second;
  }

  long double ans = (long double)abs(left_to_right - right_to_left) / 2;
  cout << fixed;
  cout.precision(1);
  cout << ans;

  return 0;
}