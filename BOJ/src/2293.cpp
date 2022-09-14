/***********************************
> File Name: 2293.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/28 01:06
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, k, input;
vector<int> coin;
vector<int> dp;

int main(void)
{
  fastio;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    cin >> input;
    coin.push_back(input);
  }

  dp.resize(k + 1, 0);
  dp[0] = 1;
  for (auto &&value : coin)
  {
    for (int i = value; i <= k; i++)
    {
      dp[i] += dp[i - value];
    }
  }

  cout << dp[k];

  return 0;
}