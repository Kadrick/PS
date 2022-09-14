#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int N;
vector<long long> dist;
vector<long long> cost;

int main(void) {
  fastio;

  cin >> N;
  dist.resize(N);
  cost.resize(N + 1);
  for (int i = 0; i < N - 1; ++i)
    cin >> dist[i + 1];
  for (int i = 0; i < N; ++i)
    cin >> cost[i + 1];

  long long pivot = cost[1], range = 0;
  long long ans = 0;
  for (int i = 1; i <= N - 1; ++i) {
    range += dist[i];
    if (i == N - 1) {
      ans += range * pivot;
      continue;
    }

    if (cost[i + 1] < pivot) {
      ans += range * pivot;
      range = 0;
      pivot = cost[i + 1];
    }
  }

  cout << ans;

  return 0;
}