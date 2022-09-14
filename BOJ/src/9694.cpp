/**
 * @file 9694.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-03-12 11:24
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

void solve()
{
  int n, m, INF = 1e9;
  cin >> n >> m;
  vector<int> dist(m, INF);
  vector<int> path(m, -1);
  vector<vector<pair<int, int>>> graph(m);
  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    graph[x].push_back({y, z});
    graph[y].push_back({x, z});
  }

  dist[0] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, 0});

  while (pq.size())
  {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (dist[here] < cost)
      continue;

    for (auto &&near : graph[here])
    {
      if (cost + near.second < dist[near.first])
      {
        dist[near.first] = cost + near.second;
        path[near.first] = here;
        pq.push({-dist[near.first], near.first});
      }
    }
  }

  if (dist[m - 1] == INF)
    cout << -1;
  else
  {
    int root = m - 1;
    vector<int> ans;
    ans.push_back(root);
    while (root)
    {
      ans.push_back(path[root]);
      root = path[root];
    }
    for (int i = ans.size() - 1; i >= 0; i--)
      cout << ans[i] << ' ';
  }
}

int main(void)
{
  fastio;

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
    cout << endl;
  }

  return 0;
}