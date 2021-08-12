#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<bool> isVisited;
vector<int> parent;
vector<vector<int>> adjlist;

void bfs() {
  queue<int> q;
  q.push(1);
  isVisited[1] = true;

  while (!q.empty()) {
    int parentNode = q.front();
    q.pop();

    for (int adjNode : adjlist[parentNode]) {
      if (!isVisited[adjNode]) {
        isVisited[adjNode] = true;
        parent[adjNode] = parentNode;
        q.push(adjNode);
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> n;
  isVisited.resize(n + 1, false);
  parent.resize(n + 1);
  adjlist.resize(n + 1, vector<int>());

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }

  bfs();

  for (int i = 2; i <= n; ++i) {
    cout << parent[i] << endl;
  }

  return 0;
}