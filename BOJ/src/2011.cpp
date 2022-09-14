#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dp[5001];
int digit[5001];
string code;
int MOD = 1000000;

int main(void) {
  fastio;

  cin >> code;

  if (code.length() > 5000) {
    cout << 0;
    return 0;
  }

  if (code[0] == '0') {
    cout << 0;
    return 0;
  }

  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= code.length(); ++i) {
    digit[i] = code[i - 1] - '0';
  }

  dp[0] = 1;
  for (int i = 1; i <= code.length(); ++i) {
    if (1 <= digit[i] && digit[i] <= 9)
      dp[i] += dp[i - 1]; // dp[i]는 이미 0이다.

    int bigger = digit[i - 1] * 10 + digit[i];
    if (10 <= bigger && bigger <= 26) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }

  cout << dp[code.length()];

  return 0;
}