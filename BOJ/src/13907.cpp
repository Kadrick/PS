/***********************************
> File Name: 13907.cpp
> Author: Kadrick
> Created Time: 2021/09/23 15:12
> Description: Dijkstra
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, k, s, d, INF = 987654321;
vector<pair<int, int>> graph[1001];
vector<int> tax;
vector<pair<long long, int>> TaxDist;

vector<vector<int>> Dijkstra(int start) {
  vector<vector<int>> ret(n + 1, vector<int>(n + 1, INF));

  priority_queue<pair<int, pair<int, int>>> pq;
  ret[start][1] = 0;
  pq.push({0, {start, 0}});

  while (!pq.empty()) {
    int dist = -pq.top().first;
    int here = pq.top().second.first;
    int waypoint = pq.top().second.second;
    pq.pop();

    if (waypoint == n)
      continue;

    if (ret[here][waypoint] < dist)
      continue;

    for (auto &there : graph[here]) {
      int moveNode = there.first;
      int movedist = dist + there.second;

      if (ret[moveNode][waypoint + 1] > movedist) {
        ret[moveNode][waypoint + 1] = movedist;
        pq.push({-movedist, {moveNode, waypoint + 1}});
      }
    }
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> n >> m >> k >> s >> d;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    tax.push_back(c);
  }

  int spath = INF, waypoint = INF;

  // find shortest path with dijkstra algorithm
  vector<vector<int>> ret = Dijkstra(s);

  for (int i = 1; i <= n; ++i) {
    if (ret[d][i] == INF)
      continue;
    if (ret[d][i] < spath) {
      spath = ret[d][i];
      waypoint = i;
    }
  }

  cout << spath << endl;

  for (int i = 1; i <= waypoint; ++i) {
    if (ret[d][i] == INF)
      continue;
    TaxDist.push_back({ret[d][i], i});
  }

  // add tax
  long long ans = 987654321123;
  for (int i = 0; i < k; ++i) {
    for (auto &path : TaxDist) {
      path.first += tax[i] * path.second;
      ans = min(ans, path.first);
    }
    cout << ans << endl;
    ans = 987654321123;
  }

  return 0;
}