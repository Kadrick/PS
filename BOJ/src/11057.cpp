// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, MOD = 10007;
int dp[1001][10];

int solve(int x, int num) {
  if (x == n)
    return 1;

  int &ret = dp[x][num];
  if (ret != -1)
    return ret;

  ret = 0;
  for (int i = num; i < 10; ++i) {
    ret += solve(x + 1, i) % MOD;
  }

  return ret %= MOD;
}

int main(void) {
  fastio;

  cin >> n;

  memset(dp, -1, sizeof(dp));

  int ans = 0;
  for (int i = 0; i < 10; ++i) {
    ans += solve(1, i);
    ans %= MOD;
  }

  cout << ans;

  return 0;
}