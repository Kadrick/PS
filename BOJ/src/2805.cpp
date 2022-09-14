#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

long long n, m, lo = 1, hi = 1, ans;
vector<long long> tree;
bool isPossible(long long h) {
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += (tree[i] - h) > 0 ? tree[i] - h : 0;
    if (sum >= m)
      return true;
  }
  return false;
}

int main(void) {
  fastio;
  cin >> n >> m;
  tree.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> tree[i];
    hi = max(hi, tree[i]);
  }

  while (lo <= hi && lo > 0) {
    long long mid = (lo + hi) / 2;
    if (isPossible(mid)) {
      lo = mid + 1;
      ans = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << endl;

  return 0;
}