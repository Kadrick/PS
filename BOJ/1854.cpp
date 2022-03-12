/**
 * @file 1854.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-03-13 04:05
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

int n, m, k, INF = 1e9;
priority_queue<pair<int, int>> pq;
vector<priority_queue<int>> dist;
vector<vector<pair<int, int>>> graph;

int main(void)
{
  fastio;

  cin >> n >> m >> k;
  graph.resize(n);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a - 1].push_back({b - 1, c});
  }

  dist.resize(n);
  dist[0].push(0);

  pq.push({0, 0});
  while (pq.size())
  {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();

    for (auto &near : graph[here])
    {
      int &next = near.first;
      int &weight = near.second;

      if (dist[next].size() < k || dist[next].top() > (weight + cost))
      {
        if (dist[next].size() == k)
          dist[next].pop();

        dist[next].push(weight + cost);
        pq.push({-(weight + cost), next});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (dist[i].size() == k)
      cout << dist[i].top() << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}