#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int w[101][101];

int main(void) {
  fastio;

  int n, m;
  cin >> n >> m;
  vector<int> order(m);
  for (int i = 0; i < m; ++i) {
    cin >> order[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> w[i + 1][j + 1];
    }
  }

  int ans = 0;
  int u = order[0];
  for (int i = 1; i < m; ++i) {
    ans += w[u][order[i]];
    u = order[i];
  }

  cout << ans;

  return 0;
}