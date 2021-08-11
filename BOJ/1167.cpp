#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int v;
int maxd, maxv;
vector<bool> isVisited;
vector<vector<pair<int, int>>> adj;

void dfs(int node, int dist) {
  if (isVisited[node])
    return;

  if (maxd < dist) {
    maxd = dist;
    maxv = node;
  }

  isVisited[node] = true;
  for (int i = 0; i < adj[node].size(); ++i) {
    dfs(adj[node][i].first, dist + adj[node][i].second);
  }
}

int main(void) {
  fastio;

  cin >> v;
  adj.resize(v + 1, vector<pair<int, int>>());
  isVisited.resize(v + 1, false);
  for (int i = 0; i < v; ++i) {
    int nodeNum;
    cin >> nodeNum;
    while (true) {
      int child;
      cin >> child;
      if (child == -1)
        break;

      int dist;
      cin >> dist;

      adj[nodeNum].push_back(make_pair(child, dist));
    }
  }

  dfs(1, 0);
  maxd = 0;
  isVisited.clear();
  isVisited.resize(v + 1, false);
  dfs(maxv, 0);

  cout << maxd;

  return 0;
}