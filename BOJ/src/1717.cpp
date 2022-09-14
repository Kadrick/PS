// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

vector<int> parent;

int Find(int v) {
  if (parent[v] == -1)
    return v;
  else
    return parent[v] = Find(parent[v]);
}

void Union(int start, int end) {
  start = Find(start);
  end = Find(end);
  if (start != end) {
    parent[start] = end;
  }
}

int main(void) {
  fastio;

  int n, m;
  cin >> n >> m;
  parent.resize(n + 1, -1);
  for (int i = 0; i < m; ++i) {
    int order, a, b;
    cin >> order >> a >> b;
    if (order == 0)
      Union(a, b);
    else {
      a = Find(a);
      b = Find(b);
      if (a != b)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }

  return 0;
}