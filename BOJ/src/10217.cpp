/**
 * @file 10217.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-04-07
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

const int INF = 1e9;

typedef struct _EDGE
{
  int target;
  int cost;
  int time;
  _EDGE(int conn, int c, int t) : target(conn), cost(c), time(t) {}
} EDGE;

int dijkstra(int &start, int &end, int &money, vector<vector<EDGE>> &graph)
{
  vector<vector<int>> dist(101, vector<int>(10001, INF));
  priority_queue<pair<int, pair<int, int>>> pq;

  dist[1][0] = 0;
  pq.push({0, {1, 0}});

  while (pq.size())
  {
    int time = -pq.top().first;
    int pos = pq.top().second.first;
    int pay = pq.top().second.second;
    pq.pop();

    if (dist[pos][pay] < time)
      continue;

    for (auto &&next : graph[pos])
    {
      if (next.cost + pay > money)
        continue;

      if (next.time + time < dist[next.target][next.cost + pay])
      {
        for (int i = next.cost + pay; i <= money; i++)
        {
          if (dist[next.target][i] > dist[pos][i - next.cost] + next.time)
              dist[next.target][i] = dist[pos][i - next.cost] + next.time;
          else
            break;
        }
        pq.push({-(next.time + time), {next.target, next.cost + pay}});
      }
    }
  }

  int ans = INF;

  for (int i = 0; i <= money; i++)
    ans = min(ans, dist[end][i]);

  return ans;
}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<EDGE>> graph(101);

  for (int i = 0; i < k; i++)
  {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph[u].push_back(EDGE(v, c, d));
  }

  int start = 1;
  int ans = dijkstra(start, n, m, graph);

  if (ans == INF)
    cout << "Poor KCM" << endl;
  else
    cout << ans << endl;

  return;
}

int main(void)
{
  fastio;

  int tc;
  cin >> tc;

  while (tc--)
    solve();

  return 0;
}