#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int v, e, src, dist;
int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;

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

  for (int i = 0; i < e; ++i) {
    int start, end, weight;
    cin >> start >> end >> weight;
    adj[start].push_back(make_pair(end, weight));
  }

  cin >> src >> dist;
  vector<int> ret = dijkstra(src);
  cout << ret[dist];

  return 0;
}