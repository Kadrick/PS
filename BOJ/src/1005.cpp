// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, w;
vector<int> t, ans;
vector<int> inDegree;
vector<vector<int>> g;

void topological(int target) {
  queue<int> q;
  //진입 차수가 0이면 큐에 넣기
  for (int i = 1; i <= n; ++i) {
    if (!inDegree[i]) {
      q.push(i);
      ans[i] = t[i];
    }
  }

  while (!q.empty()) {
    int here = q.front();
    q.pop();

    if (here == target)
    {
      cout << ans[target] << endl; 
      break;
    }
    //그래프 갱신
    for (int i = 0; i < g[here].size(); ++i) {
      inDegree[g[here][i]]--;
      ans[g[here][i]] = max(ans[g[here][i]], ans[here] + t[g[here][i]]);
      if (!inDegree[g[here][i]])
        q.push(g[here][i]);
    }
  }
  return;
}

int main(void) {
  fastio;

  int tc;
  cin >> tc;
  while (tc--) {
    ans.clear();
    t.clear();
    inDegree.clear();
    g.clear();

    cin >> n >> m;
    t.resize(n + 1, 0);
    inDegree.resize(n + 1, 0);
    g.resize(n + 1, vector<int>());
    ans.resize(n + 1, -1);

    for (int i = 0; i < n; ++i)
      cin >> t[i + 1];
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      inDegree[v]++;
    }

    cin >> w;
    topological(w);
  }

  return 0;
}