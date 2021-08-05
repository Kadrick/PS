#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
long long dp[501][501];
// 1 - 2 번째 index가 행렬 하나
long long matrixsize[502];

long long solve(int left, int right) {
  if (left == right)
    return 0;

  long long &ret = dp[left][right];
  if (ret != -1)
    return ret;

  ret = LONG_LONG_MAX;
  for (int i = left; i < right; ++i) {
    long long tmp =
        solve(left, i) + solve(i + 1, right) +
        matrixsize[left] * matrixsize[i + 1] * matrixsize[right + 1];
    ret = min(ret, tmp);
  }
  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> matrixsize[i] >> matrixsize[i + 1];
  }

  cout << solve(1, n);

  return 0;
}