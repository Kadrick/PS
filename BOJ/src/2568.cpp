#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<pair<int, int>> arr;
vector<int> L, LIS, ans;

int main(void) {
  fastio;

  cin >> n;
  LIS.resize(n, 0);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    arr.push_back(make_pair(u, v));
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; ++i) {
    int here = lower_bound(L.begin(), L.end(), arr[i].second) - L.begin();
    if (here == L.size())
      L.push_back(arr[i].second);
    else
      L[here] = arr[i].second;
    LIS[i] = here + 1;
  }

  cout << n - L.size() << endl;
  int find = L.size();
  for (int i = n - 1; i >= 0; --i) {
    if (find && LIS[i] == find) {
      find--;
    } else if (LIS[i] != find) {
      ans.push_back(arr[i].first);
    }
  }

  for (int i = ans.size() - 1; i >= 0; --i) {
    cout << ans[i] << endl;
  }

  return 0;
}