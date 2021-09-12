// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, INF = 1987654321;
int cost[21][21];
int dp[1 << 20][20];

int solve(int quest, int watch) {
  if (quest == (1 << n) - 1)
    return 0;

  int &ret = dp[quest][watch];
  if (ret != -1)
    return ret;

  ret = INF;
  for (int i = 0; i < n; ++i) {
    if (quest & (1 << i))
      continue;

    ret = min(ret, solve(quest | (1 << i), watch + 1) + cost[watch][i]);
  }

  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> cost[i][j];
    }
  }

  cout << solve(0, 0);

  return 0;
}