/***********************************
> File Name: 1766.cpp
> Author: Kadrick
> Created Time: 2021/09/20 19:45
> Description: Topological sorting + Priority Queue
***********************************/
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<int> g[32001];
int inDegree[32001];

void TopologicalSort() {
  priority_queue<int> pq;

  for (int i = 0; i < n; ++i) {
    if (inDegree[i + 1] == 0) {
      pq.push(-(i + 1));
    }
  }

  while (!pq.empty()) {
    int here = -pq.top();
    pq.pop();

    cout << here << ' ';

    for (auto &&there : g[here]) {
      inDegree[there]--;
      if (inDegree[there] == 0) {
        pq.push(-there);
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    inDegree[v]++;
  }

  TopologicalSort();

  return 0;
}