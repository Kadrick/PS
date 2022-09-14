#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dp[501][501];

int main(void) {
  fastio;
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  cin >> ans;
  dp[1][1] = ans;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      int num;
      cin >> num;
      dp[i][j] = max(dp[i - 1][j - 1] + num, dp[i - 1][j] + num);
      ans = max(dp[i][j], ans);
    }
  }

  cout << ans;
  return 0;
}