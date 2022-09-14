/**
 * @file 4803.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief DFS
 * @version 0.1
 * @date 2022-01-20 01:45
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int here, int root) {
  visited[here] = true;
  
  for (auto &&child : graph[here])
  {
    if(child == root) continue;
    if(visited[child]) return false;
    if(!dfs(child, here)) return false;
  }
  
  return true;
}

int main(void) {
  fastio;

  int round = 0;  // case counter
  while (true)
  {
    int cnt = 0; // tree counter
    graph.clear();
    visited.clear();
    cin >> n >> m;

    if(n == m && n == 0) break;

    graph.resize(n + 1, vector<int> ());
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
        if(dfs(i, 0)) cnt++;
    }

    cout << "Case " << ++round << ": ";
    if(cnt == 1) cout << "There is one tree." << endl;
    else if(cnt == 0) cout << "No trees." << endl;
    else cout << "A forest of " << cnt << " trees." << endl;
  }

  return 0;
}