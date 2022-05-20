/**
 * @file 2307.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Dijkstra
 * @version 0.1
 * @date 2022-05-20 09:20
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

int n, m, INF = 2e9;
vector<vector<pair<int, int>>> graph;

bool isIgnore(pair<int, int> edge, int u, int v)
{
  return edge == make_pair(u, v) || edge == make_pair(v, u);
}

pair<vector<pair<int, int>>, int> findShortestPath(int size, int start, int end)
{
  vector<int> dist(size + 1, INF);
  vector<int> parent(size + 1, -1);

  priority_queue<pair<int, int>> pq;
  dist[start] = 0;
  pq.push({0, start});

  while (pq.size())
  {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (dist[cur] < cost)
      continue;

    for (auto &&edge : graph[cur])
    {
      int next = edge.first;
      int money = edge.second;

      if (dist[cur] + money < dist[next])
      {
        dist[next] = dist[cur] + money;
        parent[next] = cur;
        pq.push({-dist[next], next});
      }
    }
  }

  pair<vector<pair<int, int>>, int> ret;
  ret.second = dist[end];
  while (parent[end] != -1)
  {
    ret.first.push_back({parent[end], end});
    end = parent[end];
  }
  return ret;
}

int findShortestCostWithIgnore(pair<int, int> target, int size, int start, int end)
{
  vector<int> dist(size + 1, INF);
  priority_queue<pair<int, int>> pq;
  dist[start] = 0;
  pq.push({0, start});

  while (pq.size())
  {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (dist[cur] < cost)
      continue;

    for (auto &&edge : graph[cur])
    {
      int next = edge.first;
      int money = edge.second;

      if (isIgnore(target, cur, next))
        continue;

      if (dist[cur] + money < dist[next])
      {
        dist[next] = dist[cur] + money;
        pq.push({-dist[next], next});
      }
    }
  }

  return dist[end];
}

int main(void)
{
  fastio;

  cin >> n >> m;
  graph.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b, t;
    cin >> a >> b >> t;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }

  auto ret = findShortestPath(n, 1, n);
  auto &path = ret.first;
  int &minCost = ret.second;

  if (minCost == INF)
    cout << -1 << endl;
  else
  {
    int maxCost = 0;
    for (auto &&target : path)
    {
      int cost = findShortestCostWithIgnore(target, n, 1, n);
      maxCost = max(maxCost, cost);

      if (maxCost == INF)
        break;
    }

    if (maxCost == INF)
      cout << -1 << endl;
    else
      cout << maxCost - minCost << endl;
  }

  return 0;
}