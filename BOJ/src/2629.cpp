#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, find_n;
int w[31];
bool dp[32][15001];
bool ans[15001];

void solve(int cnt, int curw) {
  if (cnt > n)
    return;

  bool &ret = dp[cnt][curw];
  if (ret != false)
    return;

  // cout << cnt << ' ' << curw << endl;
  ret = true;
  ans[curw] = true;
  solve(cnt + 1, curw + w[cnt]);
  solve(cnt + 1, curw);
  solve(cnt + 1, abs(curw - w[cnt]));
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  solve(0, 0);

  cin >> find_n;
  for (int i = 1; i <= find_n; ++i) {
    int target;
    cin >> target;
    if (target > 15000)
      cout << "N" << ' ';
    else if (ans[target])
      cout << "Y" << ' ';
    else
      cout << "N" << ' ';
  }

  return 0;
}