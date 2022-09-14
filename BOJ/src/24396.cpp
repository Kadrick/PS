/**
 * @file 24396.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-03-09 04:25
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

int n, m, d = 1;
vector<vector<int>> graph;
vector<int> dist, cnt;

int main(void)
{
  fastio;

  cin >> n >> m;
  graph.resize(n + 1);
  dist.resize(n + 1, -1);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (q.size())
  {
    int qSize = q.size();
    cnt.clear();
    cnt.resize(n + 1, 0);

    while (q.size())
    {
      int here = q.front();
      q.pop();
      for (int &near : graph[here])
        cnt[near]++;
    }

    for (int i = 1; i <= n; i++)
    {
      if (dist[i] == -1 && cnt[i] < qSize)
      {
        q.push(i);
        dist[i] = d;
      }
    }

    d++;
  }

  for (int i = 0; i < n; i++)
    cout << dist[i + 1] << endl;

  return 0;
}