/***********************************
> File Name: 7579.cpp
> Author: Kadrick
> Created Time: 2021/09/20 20:00
> Description: 0/1 Knapsack
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, INF = 1234567890;
pair<int, int> App[101];
int dp[10001];

int main(void) {
  fastio;

  int maxCost = 0;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> App[i + 1].first;
  }

  for (int i = 0; i < n; ++i) {
    cin >> App[i + 1].second;
    maxCost += App[i + 1].second;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = maxCost; j >= 0; --j) {
      if (j - App[i].second >= 0) {
        dp[j] = max(dp[j], dp[j - App[i].second] + App[i].first);
      }
    }
  }

  for (int i = 0; i <= maxCost; ++i) {
    if (!(dp[i] < m)) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}