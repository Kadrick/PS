#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, start;
vector<int> arr;
vector<bool> visited;
vector<int> ans;

void dfs(int end) {
  // cout << start << ' ' << end << endl;
  if (visited[end]) {
    if (start == end)
      ans.push_back(start);
  } else {
    visited[end] = true;
    dfs(arr[end]);
  }
}

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr[i]--;
  }

  for (int i = 0; i < n; ++i) {
    visited.clear();
    visited.resize(n, false);
    start = i;
    visited[i] = true;
    dfs(arr[i]);
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] + 1 << endl;
  }

  return 0;
}