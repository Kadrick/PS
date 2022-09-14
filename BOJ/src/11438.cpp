// author : kadrick
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<vector<int>> tree;
vector<vector<int>> parent;
vector<bool> isVisited;
vector<int> depth;

// dfs 를 통해 트리를 순회하면서
// 해당 노드의 2^0 번째 부모가 here 임을 저장한다.
// 또한 저장하는 노드의 depth를 저장한다.
void dfs(int here, int d) {
  isVisited[here] = true;
  depth[here] = d;

  for (int there : tree[here]) {
    if (isVisited[there])
      continue;
    parent[there][0] = here;
    dfs(there, d + 1);
  }
}

// 해당 노드의 2^i 번째 부모가 무엇인지를 체크한다.
void setup() {
  for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i <= n; ++i) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

// lca 를 구하자.
int LCA(int u, int v) {

  //깊이가 더 깊은 점을 v 라고 두자.
  if (depth[u] > depth[v]) {
    int tmp = u;
    u = v;
    v = tmp;
  }

  // 더 깊은 v 노드를 끌어올리는 작업을 한다
  for (int i = 20; i >= 0; --i) {
    if (depth[v] - depth[u] >= pow(2, i)) {
      v = parent[v][i];
    }
  }

  // 끌어 올렸을 때 u 와 같은가?
  if (u == v)
    return u;

  // 높이가 같으니까 서로 같이 끌어올리기
  for (int i = 20; i >= 0; --i) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int main(void) {
  fastio;

  cin >> n;
  isVisited.resize(n + 1, false);
  parent.resize(n + 1, vector<int>(21, 0));
  depth.resize(n + 1, 0);
  tree.resize(n + 1, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  // dfs 로 depth 와 바로 위(1번째) 부모를 전처리 해줌
  dfs(1, 0);

  // 2^i 번째 부모 저장해주기
  setup();

  //쿼리 시작
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    cout << LCA(u, v) << endl;
  }

  return 0;
}