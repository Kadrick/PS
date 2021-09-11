//author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

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