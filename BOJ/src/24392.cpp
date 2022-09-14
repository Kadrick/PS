/**
 * @file 24392.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-02-09 12:33
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long n, m, ans, MOD = 1e9 + 7;
long long board[1001][1001];
long long dp[1001][1001];

int main(void)
{
  fastio;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  for (int i = 0; i < m; i++)
    dp[n - 1][i] = (board[n - 1][i] == 1 ? 1 : 0);

  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j])
      {
        dp[i][j] += j > 0 ? dp[i + 1][j - 1] : 0;
        dp[i][j] %= MOD;
        dp[i][j] += dp[i + 1][j];
        dp[i][j] %= MOD;
        dp[i][j] += j < m - 1 ? dp[i + 1][j + 1] : 0;
        dp[i][j] %= MOD;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    ans += dp[0][i];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}