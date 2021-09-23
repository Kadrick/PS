/***********************************
> File Name: 1325.cpp
> Author: Kadrick
> Created Time: 2021/09/20 01:16
> Description: DFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
bool isVisited[10001];
vector<int> g[10001];

int dfs(int n) {
  if (isVisited[n])
    return 0;

  int ret = 1;
  isVisited[n] = true;
  for (auto &i : g[n]) {
    ret += dfs(i);
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }

  int max_value = -1;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    memset(isVisited, false, sizeof(isVisited));
    int ret = dfs(i + 1);
    if (max_value < ret) {
      ans.clear();
      ans.push_back(i + 1);
      max_value = ret;
    } else if (max_value == ret) {
      ans.push_back(i + 1);
    }
  }

  for (auto &i : ans) {
    cout << i << ' ';
  }

  return 0;
}