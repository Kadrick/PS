#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, m, k;
  vector<vector<int>> m1;
  vector<vector<int>> m2;
  cin >> n >> m;
  m1.resize(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> m1[i][j];
    }
  }

  cin >> m >> k;

  m2.resize(m, vector<int>(k));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> m2[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      int sum = 0;
      for (int e = 0; e < m; ++e) {
        sum += m1[i][e] * m2[e][j];
      }
      cout << sum << ' ';
    }
    cout << endl;
  }

  return 0;
}