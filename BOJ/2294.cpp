/**
 * @file 2294.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-24 09:23
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

int n, k;
vector<int> token, dp;

int main(void)
{
  fastio;

  cin >> n >> k;
  token.resize(n, 0);
  for (int i = 0; i < n; i++)
    cin >> token[i];

  sort(token.begin(), token.end());
  token.erase(unique(token.begin(), token.end()), token.end());
  n = token.size();
  dp.resize(k + 1, INT32_MAX);

  for (int i = 0; i < n; i++)
  {
    if (token[i] <= k)
      dp[token[i]] = 1;

    for (int j = token[i] + 1; j <= k; j++)
    {
      if (dp[j - token[i]] != INT32_MAX)
        dp[j] = min(dp[j], dp[j - token[i]] + 1);
      if (j % token[i] == 0)
        dp[j] = min(dp[j], j / token[i]);
    }
  }

  cout << (dp[k] == INT32_MAX ? -1 : dp[k]) << endl;

  return 0;
}