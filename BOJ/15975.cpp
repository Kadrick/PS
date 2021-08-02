#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int n;
  cin >> n;
  vector<pair<int, int>> points;
  for (int i = 0; i < n; i++) {
    int idx, color;
    cin >> idx >> color;
    points.push_back(make_pair(color, idx));
  }

  sort(points.begin(), points.end());
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    int length = 2e9;
    if (i - 1 >= 0 && points[i - 1].first == points[i].first) {
      length = min(points[i].second - points[i - 1].second, length);
    }
    if (i + 1 < n && points[i + 1].first == points[i].first) {
      length = min(points[i + 1].second - points[i].second, length);
    }
    if (length != 2e9)
      ans += length;
  }

  cout << ans << endl;
  return 0;
}