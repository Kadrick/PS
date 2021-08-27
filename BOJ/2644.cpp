#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

vector<vector<int>> edges;
vector<bool> isVisited;

int bfs(int start, int end) {
  int ret = -1;
  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  isVisited[start] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (cur.first == end) {
      ret = cur.second;
      break;
    }

    for (auto &&i : edges[cur.first]) {
      if (!isVisited[i]) {
        isVisited[i] = true;
        q.push(make_pair(i, cur.second + 1));
      }
    }
  }

  return ret;
}

int main(void) {
  fastio;

  int n, p1, p2, edge;
  cin >> n;
  cin >> p1 >> p2;
  cin >> edge;
  edges.resize(n + 1);
  isVisited.resize(n + 1, false);
  for (int i = 0; i < edge; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  cout << bfs(p1, p2);

  return 0;
}