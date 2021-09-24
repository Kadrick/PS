/***********************************
> File Name: 1309.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/24 19:15
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, mod = 9901;
int dp[100001][3];

int solve(int size, int flag) {
  if (size == 1)
    return 1;

  int &ret = dp[size][flag];
  if (ret != -1)
    return ret;

  ret = 0;

  for (int i = 0; i < 3; ++i) {
    if (i == flag && flag != 0)
      continue;
    ret += solve(size - 1, i) % mod;
  }

  return (ret %= mod);
}

int main(void) {
  fastio;

  memset(dp, -1, sizeof(dp));
  cin >> n;

  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += solve(n, i) % mod;
  }

  cout << ans % mod;

  return 0;
}