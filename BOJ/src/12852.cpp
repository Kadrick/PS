// author : kadrick
#include <bits/stdc++.h>
#include <cstring>
#include <limits>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, INF = 1e9;
int dp[1000001];
int parent[1000001];

void print(int n) {
  if(n == 1) {
    cout << 1;
    return;
  }

  cout << n << ' ';
  print(parent[n]);
}

int solve(int n) {
  if (n == 1) {
    return 0;
  }

  int &ret = dp[n];
  if (ret != -1)
    return ret;

  ret = 0;
  int c1 = INF, c2 = INF, c3 = INF;
  if (n % 3 == 0) {
    c1 = solve(n / 3) + 1;
  }
  if (n % 2 == 0) {
    c2 = solve(n / 2) + 1;
  }
  c3 = solve(n - 1) + 1;

  ret = min({c1, c2, c3});
  if(ret == c1) parent[n] = n / 3;
  if(ret == c2) parent[n] = n / 2;
  if(ret == c3) parent[n] = n - 1;

  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));
  memset(parent, -1, sizeof(parent));

  cin >> n;

  cout << solve(n) << endl;
  print(n);

  return 0;
}