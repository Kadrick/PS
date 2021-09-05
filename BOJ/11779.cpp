#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int v, e, src, dist;
int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;
vector<int> parent;
vector<int> path;

vector<int> dijkstra(int start) {
  vector<int> ret(v + 1, INF);
  ret[start] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if (ret[cur] < cost)
      continue;

    for (int i = 0; i < adj[cur].size(); ++i) {
      int moveNode = adj[cur][i].first;
      int moveCost = cost + adj[cur][i].second;

      if (ret[moveNode] > moveCost) {
        parent[moveNode] = cur;
        ret[moveNode] = moveCost;
        pq.push(make_pair(-moveCost, moveNode));
      }
    }
  }
  return ret;
}

int main(void) {
  fastio;

  cin >> v >> e;
  adj.resize(v + 1, vector<pair<int, int>>());
  parent.resize(v + 1, 0);

  for (int i = 0; i < e; ++i) {
    int start, end, weight;
    cin >> start >> end >> weight;
    adj[start].push_back(make_pair(end, weight));
  }

  cin >> src >> dist;
  vector<int> ret = dijkstra(src);
  cout << ret[dist] << endl;
  int trace = dist;
  while (parent[dist]) {
    path.push_back(dist);
    dist = parent[dist];
  }
  path.push_back(src);
  cout << path.size() << endl;
  for (int i = path.size() - 1; i >= 0; --i) {
    cout << path[i] << ' ';
  }

  return 0;
}