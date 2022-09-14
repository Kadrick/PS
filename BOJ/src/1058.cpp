/**
 * @file 1058.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Floyd-Warshall
 * @version 0.1
 * @date 2022-03-11 05:06
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

int n, ans;
vector<vector<int>> dist;

int main(void)
{
  fastio;

  cin >> n;
  dist.clear();
  dist.resize(n, vector<int>(n, 1e9));

  for (int i = 0; i < n; i++)
  {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        dist[i][j] = 0;
      dist[i][j] = (row[j] == 'Y' ? 1 : 1e9);
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      if (dist[i][j] <= 2)
        cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}