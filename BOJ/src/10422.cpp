/***********************************
> File Name: 10422.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 00:52
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int t, N;
long long dp[2501];
long long mod = 1000000007;

long long solve(int n)
{
  if (n == 0 || n == 1)
    return 1;

  long long &ret = dp[n];
  if (ret != -1)
    return ret;

  ret = 0;

  for (int i = 0; i <= n - 1; i++)
    ret += (solve(i) * solve(n - i - 1)) % mod;

  return ret %= mod;
}

int main(void)
{
  fastio;

  memset(dp, -1, sizeof(dp));

  cin >> t;
  while (t--)
  {
    cin >> N;
    cout << ((N % 2 == 0) ? solve(N / 2) : 0) << endl;
  }

  return 0;
}