/**
 * @file 1986.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-01-26 18:20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<vector<int>> board;

enum TILE
{
  NONE,
  PAWN,
  KNIGHT,
  QUEEN,
  NOTSAFE
};

bool check(int y, int x)
{
  return 1 <= y && y <= n && 1 <= x && x <= m;
}

int main(void)
{
  fastio;

  cin >> n >> m;
  board.resize(n + 1, vector<int>(m + 1, TILE::NONE));

  int cnt_queen;
  cin >> cnt_queen;
  for (int i = 0; i < cnt_queen; i++)
  {
    int r, c;
    cin >> r >> c;
    board[r][c] = TILE::QUEEN;
  }

  int cnt_knight;
  cin >> cnt_knight;
  for (int i = 0; i < cnt_knight; i++)
  {
    int r, c;
    cin >> r >> c;
    board[r][c] = TILE::KNIGHT;
  }

  int cnt_pawn;
  cin >> cnt_pawn;
  for (int i = 0; i < cnt_pawn; i++)
  {
    int r, c;
    cin >> r >> c;
    board[r][c] = TILE::PAWN;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (board[i][j] == TILE::QUEEN)
      {
        int factor[8][2] = {{0, 1},
                            {0, -1},
                            {1, 0},
                            {-1, 0},
                            {1, -1},
                            {-1, 1},
                            {1, 1},
                            {-1, -1}};

        for (int dir = 0; dir < 8; dir++)
        {
          for (int k = 1; k <= max(n, m); k++)
          {
            int nx = j + factor[dir][0] * k;
            int ny = i + factor[dir][1] * k;

            if (!check(ny, nx))
              break;
            if (board[ny][nx] == TILE::NONE)
              board[ny][nx] = TILE::NOTSAFE;
            else if (board[ny][nx] != TILE::NOTSAFE)
              break;
          }
        }
      }
      else if (board[i][j] == TILE::KNIGHT)
      {
        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        for (int k = 0; k < 8; k++)
        {
          int nx = j + dx[k];
          int ny = i + dy[k];

          if (check(ny, nx))
          {
            if (board[ny][nx] == TILE::NONE)
              board[ny][nx] = TILE::NOTSAFE;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (board[i][j] == TILE::NONE)
        ans++;
    }
  }
  cout << ans << endl;

  return 0;
}