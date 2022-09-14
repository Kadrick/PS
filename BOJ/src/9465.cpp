#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int point[2][100001];
int dp[2][100001];

int main(void) {
  fastio;

  int t;
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> point[0][i + 1];
    }
    for (int i = 0; i < n; ++i) {
      cin >> point[1][i + 1];
    }

    dp[0][1] = point[0][1];
    dp[1][1] = point[1][1];
    dp[0][2] = dp[1][1] + point[0][2];
    dp[1][2] = dp[0][1] + point[1][2];

    for (int i = 3; i <= n; ++i) {
      dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + point[0][i];
      dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + point[1][i];
    }

    cout << max(dp[0][n], dp[1][n]) << endl;
  }

  return 0;
}