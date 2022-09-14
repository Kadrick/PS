// author : kadrick
#include <bits/stdc++.h>
#include <map>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

long long n, p, q;
map<long long, long long> dp;

long long solve(long long i) {
  if (i == 0)
    return 1;

  auto ret = dp.find(i);
  if (ret != dp.end())
    return ret->second;

  dp[i] = solve(i / p) + solve(i / q);
  return dp[i];
}

int main(void) {
  fastio;

  cin >> n >> p >> q;

  cout << solve(n);

  return 0;
}