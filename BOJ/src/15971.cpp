/**
 * @file 15971.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-05-04 10:13
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

int n, s, e;
vector<pair<int, int>> graph[100001];

int solve()
{
  int ans = 0;
  vector<bool> visited(n + 1, false);
  queue<pair<int, pair<int, int>>> q;
  visited[s] = true;
  q.push({s, {0, 0}});

  while (q.size())
  {
    auto cur = q.front();
    q.pop();

    if (cur.first == e)
    {
      ans = cur.second.first - cur.second.second;
      break;
    }

    for (auto &&next : graph[cur.first])
    {
      int move = next.first;
      int cost = next.second;

      if (visited[move])
        continue;

      q.push({move, {cur.second.first + cost, max(cur.second.second, cost)}});
      visited[move] = true;
    }
  }

  return ans;
}

int main(void)
{
  fastio;

  cin >> n >> s >> e;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  cout << solve() << endl;

  return 0;
}