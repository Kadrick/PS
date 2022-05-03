/**
 * @file 25048.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-03 15:35
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

#define int long long

int n, m;
vector<int> netswitch, cost;
vector<int> dp;

int32_t main(void)
{
  fastio;

  cin >> n;
  netswitch.resize(n);
  cost.resize(n);

  for (int i = 0; i < n; i++)
    cin >> netswitch[i] >> cost[i];

  cin >> m;

  if (m == 1)
    cout << 0 << endl;
  else
  {
    dp.resize(m + 1, LLONG_MAX);

    // dp[n] = n개의 컴퓨터를 설치할 때 최소 비용
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
      // 하나는 인터넷 하나는 다른 공유기 나머지 컴퓨터라고 생각
      for (int j = m - (netswitch[i] - 2); j >= 1; j--)
      {
        // 깔끔한 연결이 아님
        if (dp[j] == LLONG_MAX)
          continue;

        // 최소 비용 연결
        dp[j + (netswitch[i] - 2)] = min(dp[j + (netswitch[i] - 2)], dp[j] + cost[i]);
      }

      // 다른 스위치를 꼽지 않고 인터넷과 컴퓨터만 연결되어 있는 경우
      if (netswitch[i] - 1 <= m)
        dp[netswitch[i] - 1] = min(dp[netswitch[i] - 1], cost[i]);
    }

    cout << (dp[m] == LLONG_MAX ? -1 : dp[m]) << endl;
  }

  return 0;
}