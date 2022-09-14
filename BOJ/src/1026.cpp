#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * b[i];
  }

  cout << ans << endl;

  return 0;
}