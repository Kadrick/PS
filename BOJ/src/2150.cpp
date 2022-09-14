/***********************************
> File Name: 2150.cpp
> Author: Kadrick, Bo Gwon Kang
> Created Time: 2021/09/22 13:46
> Description: SCC
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

// Kosaraju's Algorithm

int v, e, idx;
bool isVisited[10001];
vector<int> adj[10001];
vector<int> opposite[10001];
vector<vector<int>> ans;
stack<int> st;

void process1(int here) {
  isVisited[here] = true;

  for (auto &&there : adj[here]) {
    if (isVisited[there])
      continue;
    process1(there);
  }

  st.push(here);
}

void process2(int here, int idx) {
  isVisited[here] = true;

  for (auto &&there : opposite[here]) {
    if (isVisited[there])
      continue;
    process2(there, idx);
  }

  ans[idx].push_back(here);
}

int main(void) {
  fastio;

  cin >> v >> e;
  for (int i = 0; i < e; ++i) {
    int src, dest;
    cin >> src >> dest;
    adj[src].push_back(dest);
    opposite[dest].push_back(src);
  }

  for (int i = 0; i < v; ++i) {
    if (isVisited[i + 1])
      continue;
    process1(i + 1);
  }

  memset(isVisited, false, sizeof(isVisited));

  while (!st.empty()) {
    if (isVisited[st.top()]) {
      st.pop();
      continue;
    }
    ans.push_back(vector<int>());
    process2(st.top(), ans.size() - 1);
    st.pop();
  }

  for (int i = 0; i < ans.size(); ++i) {
    sort(ans[i].begin(), ans[i].end());
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (vector<int> &scc : ans) {
    for (int &vertex : scc) {
      cout << vertex << ' ';
    }
    cout << "-1" << endl;
  }

  return 0;
} 