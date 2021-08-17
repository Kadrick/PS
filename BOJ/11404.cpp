#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
long long INF = 987654321;
vector<vector<long long>> g(101, vector<long long>(101, INF));

int main(void) {
  fastio;

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    long long u, v, w;
    cin >> u >> v >> w;
    g[u][v] = min(g[u][v], w);
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == j)
          continue;
        g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (g[i][j] == INF)
        cout << "0" << ' ';
      else
        cout << g[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}