#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int v, e, hold1, hold2;
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

long long getDist(int v1, int v2) {
  long long ret = 0;
  vector<int> dist;
  if (v1 != 1)
    dist = dijkstra(1);
  if (!dist.empty() && dist[v1] != INF) {
    ret += dist[v1];
  } else if (!dist.empty() && dist[v1] == INF) {
    return -1;
  }
  dist.clear();
  dist = dijkstra(v1);
  if (!dist.empty() && dist[v2] != INF) {
    ret += dist[v2];
  } else if (!dist.empty() && dist[v2] == INF) {
    return -1;
  }
  dist.clear();
  if (v2 != v)
    dist = dijkstra(v2);
  if (!dist.empty() && dist[v] != INF) {
    ret += dist[v];
  } else if (!dist.empty() && dist[v] == INF) {
    return -1;
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
    adj[end].push_back(make_pair(start, weight));
  }

  long long ans = 0;
  cin >> hold1 >> hold2;
  long long path1 = getDist(hold1, hold2);
  long long path2 = getDist(hold2, hold1);

  if (path1 != -1 && path2 != -1)
    ans = min(path1, path2);
  else if (path1 == -1 && path2 == -1)
    ans = -1;
  else
    ans = max(path1, path2);

  cout << ans;

  return 0;
}