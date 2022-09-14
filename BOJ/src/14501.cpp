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
  vector<int> t(n + 1, 0);
  vector<int> p(n + 1, 0);

  int dp[17];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> p[i];
  }

  for (int day = 1; day <= n; ++day) {
    for (int progressDay = day; progressDay <= n;) {
      if (progressDay + t[progressDay] <= n + 1) {
        dp[progressDay + t[progressDay]] = max(
            dp[progressDay + t[progressDay]], dp[progressDay] + p[progressDay]);
        progressDay += t[progressDay];
      } else {
        break;
      }
    }
    int max = dp[1];
    for (int i = 2; i <= n + 1; ++i) {
      if (dp[i] < max)
        dp[i] = max;
      else
        max = dp[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n + 1; ++i) {
    ans = max(ans, dp[i]);
  }
  cout << ans;

  return 0;
}