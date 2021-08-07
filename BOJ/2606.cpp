#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int nTotalComputer;
int nEdge;
int ans;
bool adjTable[101][101];
bool isVisited[101];

void dfs(int computer) {
  ans++;
  isVisited[computer] = true;
  for (int i = 1; i <= nTotalComputer; ++i) {
    if (adjTable[computer][i] && !isVisited[i]) {
      dfs(i);
    }
  }
}

int main(void) {
  fastio;

  cin >> nTotalComputer;
  cin >> nEdge;

  for (int i = 0; i < nEdge; ++i) {
    int u, v;
    cin >> u >> v;
    adjTable[u][v] = true;
    adjTable[v][u] = true;
  }

  dfs(1);

  cout << ans - 1 << endl;

  return 0;
}