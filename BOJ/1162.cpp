/**
 * @file 1162.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-04-13 12:54
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
const int INF = LLONG_MAX;

int n, m, k, ans = INF;
vector<pair<int, int>> graph[10001];
vector<vector<int>> dist(10001, vector<int>(21, INF));

int32_t main(void)
{
  fastio;

  cin >> n >> m >> k;

  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  for (int i = 0; i < 21; i++)
    dist[1][i] = true;
  
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({0, {1, 0}});

  while (pq.size())
  {
    int cost = -pq.top().first;
    int here = pq.top().second.first;
    int fix = pq.top().second.second;
    pq.pop();

    if (dist[here][fix] < cost || here == n)
      continue;

    for (auto &&there : graph[here])
    {
      // fix
      if (fix < k && dist[there.first][fix + 1] > cost)
      {
        dist[there.first][fix + 1] = cost;
        pq.push({-cost, {there.first, fix + 1}});
      }
      // no fix
      if (dist[there.first][fix] > cost + there.second)
      {
        dist[there.first][fix] = cost + there.second;
        pq.push({-(cost + there.second), {there.first, fix}});
      }
    }
  }

  for (int i = 0; i < 21; i++)
    ans = min(ans, dist[n][i]);

  cout << ans << endl;

  return 0;
}