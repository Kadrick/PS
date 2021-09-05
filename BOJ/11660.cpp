#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, input;
int dp[1025][1025];

int main(void) {
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> input;
      dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + input;
    }
  }

  for (int i = 0; i < m; ++i) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
    cout << ans << endl;
  }

  return 0;
}