#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false);
#define endl '\n'
using namespace std;

typedef long long ll;

int n, ans;
vector<int> arr, dp;

int solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp[i] <= dp[j])
        dp[i] = dp[j] + 1;
    }

    ans = max(ans, dp[i]);
  }

  return ans;
}

int main() {

  cin >> n;
  arr.resize(n);
  dp.resize(n, 1);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << solve();

  return 0;
}
