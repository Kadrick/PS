/**
 * @file 5719.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-03-05 02:10
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

vector<vector<int>> path;
vector<int> dist;

void dijkstra(int &start)
{
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  while (pq.size())
  {
    pair<int, int> here = pq.top();
    pq.pop();

    int pos = here.second;
    int cost = -here.first;

    if (dist[pos] != -1)
      continue;

    dist[pos] = cost;
    for (int i = 0; i < path.size(); i++)
    {
      if (path[pos][i] == -1)
        continue;
      if (dist[i] != -1)
        continue;
      pq.push({-(cost + path[pos][i]), i});
    }
  }
}

void traceShortestPath(int &end)
{
  queue<int> q;
  q.push(end);
  while (q.size())
  {
    int back = q.front();
    q.pop();
    for (int i = 0; i < path.size(); i++)
    {
      if (path[i][back] == -1)
        continue;
      if (dist[back] == dist[i] + path[i][back])
      {
        path[i][back] = -1;
        q.push(i);
      }
    }
  }
}

int main(void)
{
  fastio;

  while (true)
  {
    int n, m;
    cin >> n >> m;

    path.resize(n, vector<int>(m, -1));
    dist.resize(n, -1);

    if (n == 0 && m == 0)
      break;

    int start, end;
    cin >> start >> end;

    for (int i = 0; i < m; i++)
    {
      int u, v, p;
      cin >> u >> v >> p;
      path[u][v] = p;
    }

    dijkstra(start);
    traceShortestPath(end);

    dist.clear();
    dist.resize(n, -1);

    dijkstra(start);

    cout << dist[end] << endl;

    path.clear();
    dist.clear();
  }

  return 0;
}