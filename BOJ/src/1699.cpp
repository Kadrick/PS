#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<int> dp;

int solve(int num) {
  // cout << num << endl;
  if (num <= 0)
    return 0;

  int &ret = dp[num];
  if (ret != -1)
    return ret;

  ret = 987654321;
  for (int i = 1; i * i <= num; ++i) {
    ret = min(ret, solve(i * i) + solve(num - i * i));
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> n;
  dp.resize(n + 1, -1);
  for (int i = 1; i * i <= n; ++i) {
    dp[i * i] = 1;
  }

  cout << solve(n);

  return 0;
}