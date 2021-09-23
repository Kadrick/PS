/***********************************
> File Name: 17404.cpp
> Author: Kadrick
> Created Time: 2021/09/20 19:20
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, INF = 987654321, lastkey;
int cost[1001][3];
int dp[1001][3];

int solve(int n, int color) {
  if (n == 1) {
    if (lastkey == color)
      return INF;
    return cost[n][color];
  }
  int &ret = dp[n][color];
  if (ret != -1)
    return ret;

  ret = INF;
  int comp = cost[n][color];
  for (int i = 0; i < 2; ++i) {
    color = (color + 1) % 3;
    ret = min(ret, solve(n - 1, color) + comp);
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cost[i + 1][0] >> cost[i + 1][1] >> cost[i + 1][2];
  }

  int ans = INF;
  for (int i = 0; i < 3; ++i) {
    lastkey = i;
    memset(dp, -1, sizeof(dp));
    ans = min(ans, solve(n, i));
  }

  cout << ans;

  return 0;
}