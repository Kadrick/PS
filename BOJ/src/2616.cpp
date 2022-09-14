/**
 * @file 2616.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-20 10:52
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

int total, unit;
vector<int> preSum;
vector<vector<int>> dp;

int solve(int remains, int lastPos)
{
  // remains : 남은 소형 기관차의 수
  // lastPos : 마지막 객차의 위치
  if (remains == 0 || lastPos == 0)
    return 0;

  int &ret = dp[remains][lastPos];
  if (ret != -1)
    return ret;

  ret = solve(remains, lastPos - 1);
  if (lastPos - unit >= 0)
    ret = max(ret, solve(remains - 1, lastPos - unit) + preSum[lastPos] - preSum[lastPos - unit]);

  return ret;
}

int main(void)
{
  fastio;

  cin >> total;
  preSum.push_back(0);
  for (int i = 1; i <= total; i++)
  {
    int human;
    cin >> human;
    preSum.push_back(preSum[i - 1] + human);
  }
  cin >> unit;

  dp.resize(4, vector<int>(total + 1, -1));
  cout << solve(3, total) << endl;

  return 0;
}