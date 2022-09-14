/**
 * @file 1983.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-04 21:44
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

int n;
vector<int> arr[2];
vector<vector<vector<int>>> dp;

int solve(int pivot, int aIdx, int bIdx)
{
  // 계산을 할 수가 남지 않았다면
  if (aIdx == arr[0].size() || bIdx == arr[1].size())
    return 0;

  int &ret = dp[pivot][aIdx][bIdx];
  if (ret != -INT32_MIN)
    return ret;

  ret = solve(pivot + 1, aIdx + 1, bIdx + 1) + arr[0][aIdx] * arr[1][bIdx];

  if (n - pivot > arr[0].size() - aIdx)
    ret = max(ret, solve(pivot + 1, aIdx, bIdx + 1));

  if (n - pivot > arr[1].size() - bIdx)
    ret = max(ret, solve(pivot + 1, aIdx + 1, bIdx));

  return ret;
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int input;
      cin >> input;
      if (input != 0)
        arr[i].push_back(input);
    }
  }

  dp.resize(n, vector<vector<int>>(n, vector<int>(n, INT32_MIN)));

  cout << solve(0, 0, 0) << endl;

  return 0;
}