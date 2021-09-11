// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, c;
int ruby[14];
// 보석, 가방, 가방크기
int dp[1 << 14][11][21];

// idx 가방에 capacity 만큼의 용량이 있을 때 먹을 수 있는 최대 보석
int solve(int diamond, int idx, int capacity) {
  //기저사례: 보석을 모두 먹었거나, 가방을 모두 사용했을 때
  if (diamond == (1 << n) - 1 || idx == m)
    return 0;

  int &ret = dp[diamond][idx][capacity];
  if (ret != -1)
    return ret;

  ret = 0;

  //모든 보석을 체크함
  for (int i = 0; i < n; ++i) {
    //만약 이미 가진 보석이면 continue
    if (diamond & (1 << i))
      continue;

    //만약 가방에 넣을 수 있다면 가방에 넣고 해당 가방을 계속 사용하기
    if (capacity >= ruby[i])
      ret = max(ret, solve(diamond | (1 << i), idx, capacity - ruby[i]) + 1);
    //만약 가방에 넣을 수 없다면 다음 가방조사
    else
      ret = max(ret, solve(diamond, idx + 1, c));
  }

  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> c;
  for (int i = 0; i < n; ++i) {
    cin >> ruby[i];
  }

  cout << solve(0, 0, c);

  return 0;
}