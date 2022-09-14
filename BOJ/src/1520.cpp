/***********************************
> File Name: 1520.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/05 20:25
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int m, n;
int board[501][501];
int dp[501][501];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool inRange(int y, int x) {
  return 1 <= y && y <= m && 1 <= x && x <= n;
}

int solve(int y, int x)
{
  if (y == 1 && x == 1)
    return 1;

  int& ret = dp[y][x];
  if(ret != -1) return ret;

  ret = 0;
  for (int i = 0; i < 4; i++)
  {
    int movey = y + dy[i];
    int movex = x + dx[i];

    if(!inRange(movey, movex)) continue;
    if(board[y][x] < board[movey][movex])
      ret += solve(movey, movex);
  }
  
  return ret;  
}

int main(void)
{
  fastio;

  memset(dp, -1, sizeof(dp));
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> board[i][j];
  }

  cout << solve(m, n);

  return 0;
}