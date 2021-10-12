/***********************************
> File Name: 2747.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 18:57
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
long long dp[50];

long long fibo(int n)
{
  if (n == 0 || n == 1)
    return n;

  long long &ret = dp[n];
  if (ret != -1)
    return ret;

  ret = fibo(n - 1) + fibo(n - 2);
  return ret;
}

int main(void)
{
  fastio;
  memset(dp, -1, sizeof(dp));
  cin >> n;
  cout << fibo(n);

  return 0;
}