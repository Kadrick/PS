#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int v, e;
vector<vector<int>> edges;
vector<int> flag;
enum color { nothing, white, black };

bool bfs(int v) {
  bool ans = true;
  queue<int> q;
  q.push(v);
  flag[v] = color::white;

  while (!q.empty() && ans) {
    int cur = q.front();
    q.pop();

    for (auto v : edges[cur]) {
      if (flag[v] == color::nothing) {
        q.push(v);
        flag[v] = flag[cur] == color::black ? color::white : color::black;
      } else if (flag[v] == flag[cur]) {
        ans = false;
        break;
      }
    }
  }

  return ans;
}

int main(void) {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    cin >> v >> e;
    edges.clear();
    edges.resize(v + 1, vector<int>());
    flag.clear();
    flag.resize(v + 1, 0);

    for (int i = 0; i < e; ++i) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }

    bool ans = true;

    for (int i = 1; i <= v; ++i) {
      if (flag[i] == color::nothing) {
        ans = ans && bfs(i);
        if (!ans)
          break;
      }
    }

    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}