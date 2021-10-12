/***********************************
> File Name: 2169.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/11 19:52
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
int value[1001][1001];
int dp[1001][1001][3];

int solve(int y, int x, int dir)
{
  if (y == 0 || x == 0 || x == m + 1)
    return -987654321;
  if (y == 1 && x == 1)
    return value[y][x];

  int &ret = dp[y][x][dir];
  if (ret != -1)
    return ret;

  ret = value[y][x];

  switch (dir)
  {
  case 0:
    ret += max({solve(y - 1, x, 0),
                solve(y, x - 1, 1),
                solve(y, x + 1, 2)});
    break;
  case 1:
    ret += max({solve(y - 1, x, 0),
                solve(y, x - 1, 1)});
    break;
  case 2:
    ret += max({solve(y - 1, x, 0),
                solve(y, x + 1, 2)});
    break;
  }

  return ret;
}

int main(void)
{
  fastio;

  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> value[i + 1][j + 1];
  }

  cout << max({solve(n, m, 0), solve(n, m, 1)});

  return 0;
}