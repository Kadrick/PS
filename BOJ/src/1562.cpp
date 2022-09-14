#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;

int MOD = 1000000000;
//시작하는 수 : 길이 : 방문여부 (0-9까지 모두 등장해야함)
int dp[10][101][1 << 10];

int solve(int startNum, int length, int visit) {
  //기저사례: 0-9까지 모두 등장했다면 계단수 하나
  if (length == n) {
    if (visit == (1 << 10) - 1)
      return 1;
    else
      return 0;
  }

  //메모이제이션
  int &ret = dp[startNum][length][visit];
  if (ret != -1)
    return ret;

  ret = 0;

  if (startNum - 1 >= 0)
    ret += solve(startNum - 1, length + 1, visit | 1 << (startNum - 1));
  if (startNum + 1 <= 9)
    ret += solve(startNum + 1, length + 1, visit | 1 << (startNum + 1));

  ret %= MOD;

  return ret;
}

int main(void) {
  fastio;
  cin >> n;

  int ans = 0;
  for (int i = 1; i <= 9; ++i) {
    memset(dp, -1, sizeof(dp));
    ans += solve(i, 1, 1 << i);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}