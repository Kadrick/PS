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

bool BellmanFord(vector<Edge> &edges, int M, int N, int src) {
  vector<int> dist(N + 2, INF);
  dist[src] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (dist[edges[j].src] == INF)
        continue;
      dist[edges[j].dest] =
          min(dist[edges[j].dest], dist[edges[j].src] + edges[j].weight);
    }
  }

  bool ret = true;
  for (int i = 0; i < M; ++i) {
    if (dist[edges[i].src] != INF &&
        dist[edges[i].dest] > dist[edges[i].src] + edges[i].weight)
      return ret;
  }
  ret = false;
  return ret;
}

int main(void) {
  fastio;
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> w;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
      cin >> s >> e >> t;
      edges.push_back(Edge(s, e, t));
      edges.push_back(Edge(e, s, t));
    }
    for (int i = 0; i < w; ++i) {
      cin >> s >> e >> t;
      edges.push_back(Edge(s, e, -1 * t));
    }

    for (int i = 0; i < n; ++i) {
      edges.push_back(Edge(n + 1, i + 1, 0));
    }

    if (BellmanFord(edges, edges.size(), n, n + 1))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}