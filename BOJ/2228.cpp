/**
 * @file 2228.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-03-06 01:37
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

int n, m;
vector<int> arr;
vector<vector<int>> dp, sum;

int solve(int end, int seg)
{
  if (seg == 0)
    return 0;
  if (end < 0)
    return -1e9;

  int &ret = dp[end][seg];
  if (ret != 1e9)
    return ret;

  ret = solve(end - 1, seg);
  for (int i = end; i >= 0; i--)
    ret = max(ret, sum[i][end] + solve(i - 2, seg - 1));

  return ret;
}

int main(void)
{
  fastio;
  cin >> n >> m;
  arr.resize(n);
  dp.resize(n, vector<int>(m + 1, 1e9));
  sum.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
  {
    int tmp = 0;
    for (int j = i; j < n; j++)
    {
      tmp += arr[j];
      sum[i][j] = tmp;
    }
  }

  cout << solve(n - 1, m) << endl;

  return 0;
}