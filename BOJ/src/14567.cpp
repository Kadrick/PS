#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<int> inDegree;
vector<int> ans;
vector<vector<int>> g;

void topological() {
  queue<pair<int, int>> q;
  //진입 차수가 0이면 큐에 넣기
  for (int i = 1; i <= n; ++i) {
    if (!inDegree[i])
      q.push(make_pair(i, 1));
  }

  while (!q.empty()) {
    auto cur = q.front();
    int here = cur.first;
    int semester = cur.second;
    q.pop();

    ans[here] = semester;
    //그래프 갱신
    for (int i = 0; i < g[here].size(); ++i) {
      inDegree[g[here][i]]--;
      if (!inDegree[g[here][i]])
        q.push(make_pair(g[here][i], semester + 1));
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> m;
  inDegree.resize(n + 1, 0);
  ans.resize(n + 1, 0);
  g.resize(n + 1, vector<int>());
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    inDegree[v]++;
  }

  topological();

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }

  return 0;
}