#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, k, x;
vector<vector<int>> adj;
vector<bool> isVisited;

vector<int> bfs(int start, int dist) {
  vector<int> ret;

  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  isVisited[start] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    if (cur.second == dist) {
      ret.push_back(cur.first);
      continue;
    }

    for (auto connectedNode : adj[cur.first]) {
      if (!isVisited[connectedNode]) {
        q.push(make_pair(connectedNode, cur.second + 1));
        isVisited[connectedNode] = true;
      }
    }
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> n >> m >> k >> x;
  adj.resize(n + 1, vector<int>());
  isVisited.resize(n + 1, false);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  auto ret = bfs(x, k);
  sort(ret.begin(), ret.end());
  if (ret.size())
    for (auto node : ret)
      cout << node << endl;
  else
    cout << -1 << endl;
  return 0;
}