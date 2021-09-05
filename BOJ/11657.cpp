#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, w;
int s, e, t;
int INF = INT_MAX;
typedef struct _Edge {
  int src;
  int dest;
  int weight;
  _Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
} Edge;

void BellmanFord(vector<Edge> edges, int M, int N, int src) {
  vector<long long> dist(N + 1, INF);
  dist[src] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (dist[edges[j].src] == INF)
        continue;
      if (dist[edges[j].dest] > dist[edges[j].src] + edges[j].weight) {
        dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
      }
    }
  }

  for (int i = 0; i < M; ++i) {
    if (dist[edges[i].src] == INF)
      continue;
    if (dist[edges[i].dest] > dist[edges[i].src] + edges[i].weight) {
      cout << -1 << endl;
      return;
    }
  }

  for (int i = 1; i < N; ++i) {
    cout << ((dist[i + 1] != INF) ? dist[i + 1] : -1) << endl;
  }
  return;
}

int main(void) {
  fastio;

  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    cin >> s >> e >> t;
    edges.push_back(Edge(s, e, t));
  }

  BellmanFord(edges, edges.size(), n, 1);

  return 0;
}