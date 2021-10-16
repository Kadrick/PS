/***********************************
> File Name: 2133.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/17 01:47
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
int dp[31];

int solve(int n)
{
  if(n % 2) return 0;

  int &ret = dp[n];
  if (ret != -1)
    return ret;

  ret = 0;
  ret += solve(n - 2) * 3;
  for (int i = 0; i < n - 2; i += 2)
    ret += solve(i) * 2;

  return ret;
}

int main(void)
{
  fastio;

  memset(dp, -1, sizeof(dp));
  dp[0] = 1;
  dp[2] = 3;
  cin >> n;
  cout << solve(n);

  return 0;
}