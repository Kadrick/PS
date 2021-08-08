#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<int> arr;
vector<bool> isVisited;

void solve(vector<int> &ans, int idx) {
  if (ans.size() == m) {
    for (auto i : ans)
      cout << i << ' ';
    cout << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (!isVisited[i]) {
      ans.push_back(arr[i]);
      isVisited[i] = true;
      solve(ans, i + 1);
      ans.pop_back();
      isVisited[i] = false;
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> m;
  arr.resize(n);
  isVisited.resize(n, false);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<int> tmp;
  solve(tmp, 0);

  return 0;
}