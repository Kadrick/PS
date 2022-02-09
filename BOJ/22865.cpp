/**
 * @file 22865.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-02-10 01:42
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

int n, friends[3], m;
vector<vector<int>> storage(3);
vector<vector<pair<int, int>>> adj;

vector<int> get_min_dist(int start)
{
  vector<int> ret(n + 1, 1e9);
  ret[start] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (ret[cur] < cost)
      continue;

    for (int i = 0; i < adj[cur].size(); ++i)
    {
      int moveNode = adj[cur][i].first;
      int moveCost = cost + adj[cur][i].second;

      if (ret[moveNode] > moveCost)
      {
        ret[moveNode] = moveCost;
        pq.push(make_pair(-moveCost, moveNode));
      }
    }
  }
  return ret;
}

int main(void)
{
  fastio;

  cin >> n >> friends[0] >> friends[1] >> friends[2] >> m;
  adj.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  for (int i = 0; i < 3; i++)
    storage[i] = get_min_dist(friends[i]);

  int ans = 0, max_dist = 0, min_dist = 1e9;
  for (int i = 1; i <= n; i++)
  {
    bool start = false;
    for (int j = 0; j < 3; j++)
    {
      if (friends[j] == i)
      {
        start = true;
        false;
      }
    }

    if (start)
      continue;

    min_dist = 1e9;
    for (int j = 0; j < 3; j++)
      min_dist = min(min_dist, storage[j][i]);

    if (min_dist > max_dist)
    {
      ans = i;
      max_dist = min_dist;
    }
  }

  cout << ans << endl;

  return 0;
}