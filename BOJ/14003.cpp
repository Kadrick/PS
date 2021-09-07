#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<int> arr, L, LIS, ans;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n + 1, 0);
  LIS.resize(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    int here = lower_bound(L.begin(), L.end(), arr[i]) - L.begin();
    if (here == L.size()) {
      L.push_back(arr[i]);
    } else
      L[here] = arr[i];
    LIS[i] = here + 1;
  }

  cout << L.size() << endl;
  int find = L.size();
  for (int i = n; i >= 0; --i) {
    if (find && LIS[i] == find) {
      ans.push_back(arr[i]);
      find--;
    }
  }

  for (int i = ans.size() - 1; i >= 0; --i) {
    cout << ans[i] << ' ';
  }

  return 0;
}