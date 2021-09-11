// author : kadrick
#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, input;
vector<int> arr;

void trace(int idx, vector<int> &ans) {
  if (ans.size() == m) {
    for (int i = 0; i < m; ++i)
      cout << ans[i] << ' ';
    cout << endl;
    return;
  }

  for (int i = idx; i <= n; ++i) {
    ans.push_back(arr[i]);
    trace(i, ans);
    ans.pop_back();
  }
}

int main(void) {
  fastio;

  cin >> n >> m;
  arr.push_back(0);
  for (int i = 0; i < n; ++i) {
    cin >> input;
    if (find(arr.begin(), arr.end(), input) == arr.end())
      arr.push_back(input);
  }

  sort(arr.begin(), arr.end());

  n = arr.size() - 1;
  vector<int> ans;
  trace(1, ans);

  return 0;
}