// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, ans;
vector<int> arr;
vector<int> dp;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n + 1, 0);
  dp.resize(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i + 1];
  }

  ans = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (arr[j] > arr[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        ans = max(ans, dp[i]);
      }
    }
  }

  cout << ans;

  return 0;
}