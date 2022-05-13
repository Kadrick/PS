/**
 * @file 2515.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-13 13:13
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

int n, s;
vector<int> dp;
vector<pair<int, int>> arr;

bool comp(pair<int, int> left, pair<int, int> right)
{
  if (left.first == right.first)
    return left.second < right.second;
  return left.first < right.first;
}

int main(void)
{
  fastio;

  cin >> n >> s;
  dp.resize(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    int h, c;
    cin >> h >> c;
    arr.push_back({h, c});
  }
  sort(arr.begin(), arr.end(), comp);

  dp[0] = arr[0].second;
  for (int i = 1; i < n; i++)
  {
    dp[i] = dp[i - 1];
    pair<int, int> target = {arr[i].first - s + 1, 0};
    int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (pos == 0)
      dp[i] = max(dp[i], arr[i].second);
    else
      dp[i] = max(dp[i], dp[pos - 1] + arr[i].second);
  }

  cout << dp[n - 1] << endl;

  return 0;
}