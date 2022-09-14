#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int nVertex;
int nEdge;
int ans;
bool adjTable[1001][1001];
bool isVisited[1001];

void dfs(int vertex) {
  isVisited[vertex] = true;
  for (int i = 1; i <= nVertex; ++i) {
    if (adjTable[vertex][i] && !isVisited[i]) {
      dfs(i);
    }
  }
}

int main(void) {
  fastio;

  cin >> nVertex;
  cin >> nEdge;

  for (int i = 0; i < nEdge; ++i) {
    int u, v;
    cin >> u >> v;
    adjTable[u][v] = true;
    adjTable[v][u] = true;
  }

  for (int i = 1; i <= nVertex; ++i) {
    if (!isVisited[i]) {
      ans++;
      dfs(i);
    }
  }

  cout << ans;

  return 0;
}