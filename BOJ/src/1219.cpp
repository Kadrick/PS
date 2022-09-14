/***********************************
> File Name: 1219.cpp
> Author: Kadrick / Bo Gwon Kang
> Created Time: 2021/09/15
> Description: Bellman Ford
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef struct _Edge {
  int src;
  int dest;
  int weight;
  _Edge(int u, int v, int cost) {
    src = u;
    dest = v;
    weight = cost;
  }
} Edge;

bool isCycle = false;
int n, m, src, dest, INF = 2100000000;
vector<int> city;
vector<Edge> edges;
vector<bool> isVisited;

bool dfs(int check) {
  bool ret = false;
  isVisited[check] = true;
  if (check == dest)
    return true;

  for (auto e : edges) {
    if (e.src == check && !isVisited[e.dest])
      if (dfs(e.dest))
        return true;
  }
  return ret;
}

vector<long long> BellmanFord(vector<Edge> &edges, int source) {
  vector<long long> dist(n, INF);
  dist[src] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < edges.size(); j++) {
      if (dist[edges[j].src] == INF)
        continue;
      if (dist[edges[j].dest] > dist[edges[j].src] + edges[j].weight)
        dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
    }
  }
  for (int i = 0; i < edges.size(); i++) {
    if (dist[edges[i].src] == INF) continue;
    if (dist[edges[i].dest] > dist[edges[i].src] + edges[i].weight) {
      isVisited.resize(n, false);
      if(dfs(edges[i].dest))
        isCycle = true;
    }
  }
  return dist;
}

int main(void) {
  fastio;
  cin >> n >> src >> dest >> m;
  city.resize(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v, weight;
    cin >> u >> v >> weight;
    edges.push_back(Edge(u, v, weight));
  }
  for (int i = 0; i < n; ++i) {
    cin >> city[i];
  }

  for (int i = 0; i < edges.size(); ++i) {
    edges[i].weight = edges[i].weight - city[edges[i].dest];
  }

  vector<long long> ret = BellmanFord(edges, src);

  if (ret[dest] == INF) {
    cout << "gg";
  } else if (isCycle) {
    cout << "Gee";
  } else {
    cout << -ret[dest] + city[src];
  }

  return 0;
}