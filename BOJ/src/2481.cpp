/**
 * @file 2481.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-05-10 09:16
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

int n, k, m;
vector<int> require, parent;
vector<vector<int>> graph;
map<string, int> table;

void bfs()
{
  queue<int> q;
  q.push(0);

  while (q.size())
  {
    auto here = q.front();
    q.pop();

    for (auto &&there : graph[here])
    {
      if (parent[there] != -1 || there == 0)
        continue;

      parent[there] = here;
      q.push(there);
    }
  }
}

int main(void)
{
  fastio;

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;
    table[input] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int in;
    cin >> in;
    require.push_back(in);
  }

  parent.resize(n, -1);
  graph.resize(n);

  // make graph
  for (auto &&iter : table)
  {
    for (int i = 0; i < k; i++)
    {
      string cpy = iter.first;
      cpy[i] = iter.first[i] == '0' ? '1' : '0';
      if (table.find(cpy) != table.end())
        graph[iter.second].push_back(table[cpy]);
    }
  }

  bfs();

  for (int i = 0; i < m; i++)
  {
    if (parent[require[i] - 1] == -1)
      cout << -1 << endl;
    else
    {
      vector<int> ans;
      int end = require[i] - 1;

      while (end != -1)
      {
        ans.push_back(end + 1);
        end = parent[end];
      }

      for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
      cout << endl;
    }
  }

  return 0;
}