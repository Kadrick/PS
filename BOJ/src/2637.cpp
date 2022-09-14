/**
 * @file 2637.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Topological sorting
 * @version 0.1
 * @date 2022-05-12 10:26
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

int n, m;
vector<int> inDeg;
vector<bool> type;
vector<vector<int>> table;
vector<vector<pair<int, int>>> graph;

int main(void)
{
  fastio;

  cin >> n >> m;
  type.resize(n + 1, false);
  inDeg.resize(n + 1, 0);
  table.resize(n + 1, vector<int>(n + 1, 0));
  graph.resize(n + 1);
  for (int i = 0; i < m; i++)
  {
    int x, y, k;
    cin >> x >> y >> k;
    graph[y].push_back({x, k});
    inDeg[x]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (inDeg[i] == 0)
    {
      q.push(i);
      type[i] = true;
    }
  }

  while (q.size())
  {
    int here = q.front();
    q.pop();

    for (auto &&there : graph[here])
    {
      inDeg[there.first]--;
      if (type[here])
        table[here][there.first] += there.second;
      else
      {
        for (int i = 1; i <= n; i++)
        {
          if (type[i])
            table[i][there.first] += table[i][here] * there.second;
        }
      }

      if (inDeg[there.first] == 0)
        q.push(there.first);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (type[i])
    {
      cout << i << ' ';
      cout << table[i][n] << endl;
    }
  }

  return 0;
}