/***********************************
> File Name: 11048.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/11 18:33
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
int dp[1001][1001];
int candy[1001][1001];

int main(void)
{
  fastio;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> candy[i + 1][j + 1];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
      dp[i][j] = candy[i][j] + max({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
  }
  cout << dp[n][m];

  return 0;
}