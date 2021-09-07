#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int INF = 1e9;
int n, weight[16][16], dp[16][1 << 16];

// here: 현재 방문도시 / visited: 방문한 도시 집합
int tsp(int here, int visited) {
  //기저 사례: 모든 도시를 방문했더라면 현재 도시에서 시작도시(0)에 도달할 수
  //있는가?
  if (visited == (1 << n) - 1) {
    if (weight[here][0] != 0)
      return weight[here][0];
    return INF;
  }

  int &ret = dp[here][visited];
  if (ret != -1)
    return ret;

  ret = INF;
  for (int i = 0; i < n; ++i) {
    // i번재 정점을 지난적있는지 이동할 수 있는 길이 있는지 체크
    if (visited & (1 << i) || !weight[here][i])
      continue;
    ret = min(ret, tsp(i, visited | (1 << i)) + weight[here][i]);
  }
  return ret;
}

int main(void) {
  fastio;
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> weight[i][j];
    }
  }

  cout << tsp(0, 1);

  return 0;
}