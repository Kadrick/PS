#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  int exclude = round((double)n / 100 * 15);
  vector<int> point(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> point[i];
  }

  sort(point.begin(), point.end());

  int sum = 0;
  for (int i = exclude; i < n - exclude; ++i) {
    sum += point[i];
  }

  int ans = round((double)sum / (n - 2 * exclude));
  cout << ans;

  return 0;
}