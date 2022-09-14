// author : kadrick
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
long long mod = 1000000009;
long long dp[1000001];

long long solve(int n) {
  if (n <= 1)
    return 1;

  long long &ret = dp[n];
  if (ret != -1)
    return ret;

  ret = 0;
  if (n >= 1)
    ret += solve(n - 1) % mod;
  if (n >= 2)
    ret += solve(n - 2) % mod;
  if (n >= 3)
    ret += solve(n - 3) % mod;
  ret %= mod;
  return ret;
}

int main(void) {
  fastio;

  memset(dp, -1, sizeof(dp));
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    cout << solve(n) << endl;
  }

  return 0;
}