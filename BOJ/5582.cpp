#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dp[4001][4001];

int main(void) {
  fastio;

  int ans = 0;
  string A, B;
  cin >> A >> B;

  for (int i = 1; i <= A.length(); ++i) {
    for (int j = 1; j <= B.length(); ++j) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;

        ans = max(ans, dp[i][j]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}