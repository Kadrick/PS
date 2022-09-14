// author : kadrick
#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

// Kruskal
/*
typedef struct _Edge {
  int start;
  int end;
  int cost;
  _Edge (int u, int v, int m) {
    start = u;
    end = v;
    cost = m;
  }
}Edge;

bool comp(const Edge& left, const Edge& right) {
  return left.cost < right.cost;
}

int v, e, src, dest, cost;
vector<Edge> edges;
vector<int> parent;

int Find(int v) {
  if(parent[v] == 0) return v;
  else return parent[v] = Find(parent[v]);
}

bool Union(int start, int end) {
  start = Find(start);
  end = Find(end);
  if(start != end) {
    parent[start] = end;
    return true;
  }

  return false;
}


int main(void) {
  fastio;

  cin >> v >> e;
  parent.resize(v+1, 0);
  for (int i = 0; i < e; ++i) {
    cin >> src  >> dest >> cost;
    edges.push_back(Edge(src,dest,cost));
  }

  sort(edges.begin(), edges.end(), comp);

  int ans = 0;

  for(auto& e : edges) {
    if(Union(e.start, e.end)) {
      ans += e.cost;
    }
  }

  cout << ans;

  return 0;
}
*/

// Prim
int v, e, src, dest, cost;
vector<vector<pair<int, int>>> g;
vector<bool> isVisited;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main(void) {
  fastio;

  cin >> v >> e;
  g.resize(v + 1, vector<pair<int, int>>());
  isVisited.resize(v + 1, false);
  for (int i = 0; i < e; ++i) {
    cin >> src >> dest >> cost;
    g[src].push_back({dest, cost});
    g[dest].push_back({src, cost});
  }

  int ans = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    int money = pq.top().first;
    int start = pq.top().second;
    pq.pop();

    if (isVisited[start])
      continue;
    isVisited[start] = true;

    ans += money;

    for (int i = 0; i < g[start].size(); ++i) {
      pq.push({g[start][i].second, g[start][i].first});
    }
  }

  cout << ans;
  return 0;
}