// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<pair<int, int>> arr;

int main(void) {
  fastio;

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    if (v < u)
      arr.push_back({v, u});
  }
  arr.push_back({m + 1, m + 1});
  sort(arr.begin(), arr.end());

  long long ans = 0;
  long long src = 0, dest = 0, ns = -1, ne = -1;
  for (int i = 0; i < arr.size(); ++i) {
    src = arr[i].first;
    dest = arr[i].second;
    if (ns <= src && dest <= ne)
      continue;
    if (ne < src) {
      ans += 2 * (ne - ns);
      ns = src;
    }
    ne = dest;
  }

  ans += m;
  cout << ans;

  return 0;
}