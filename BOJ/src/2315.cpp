#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int N, M;
int d[1001];
long long w[1001];
long long dp[1001][1001][2];
long long wsum[1001];

long long solve(int left, int right, int flag) {
  // base case : 가로등을 다 끔
  if (left == 1 && right == N)
    return 0;

  // left 에서 right 까지 다 끈 가로등이 존재 한다면 return
  long long &ret = dp[left][right][flag];
  if (ret != -1)
    return ret;

  ret = LONG_LONG_MAX;
  long long sec;
  //왼쪽으로 갈 수 있다면
  if (left > 1) {
    //현재 위치에서 왼쪽으로 가보자.
    if (flag)
      sec = d[right] - d[left - 1];
    else
      sec = d[left] - d[left - 1];
    ret = min(ret, solve(left - 1, right, 0) +
                       sec * (wsum[N] - wsum[right] + wsum[left - 1]));
  }
  if (right < N) {
    if (flag)
      sec = d[right + 1] - d[right];
    else
      sec = d[right + 1] - d[left];
    ret = min(ret, solve(left, right + 1, 1) +
                       sec * (wsum[N] - wsum[right] + wsum[left - 1]));
  }
  // cout << left << ' ' << right << ' ' << flag << " ret: " << ret << endl;

  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> d[i] >> w[i];
    wsum[i] = w[i] + wsum[i - 1];
  }

  cout << solve(M, M, 0);

  return 0;
}