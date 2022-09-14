/**
 * @file 1704.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief bitmask
 * @version 0.1
 * @date 2022-02-17 04:15
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

int row, col;
int min_flip = 987654321;

vector<vector<int>> board;
vector<vector<int>> toggle;
vector<vector<int>> candidate;
vector<vector<int>> ans;

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

bool inRange(int y, int x)
{
  return 0 <= y && y < row && 0 <= x && x < col;
}

void change(int y, int x)
{
  for (int i = 0; i < 5; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (inRange(ny, nx))
      toggle[ny][nx] = !toggle[ny][nx];
  }
}

bool check(int seed)
{
  int flip = 0;
  toggle = board;
  candidate.clear();
  candidate.resize(row, vector<int>(col, 0));

  for (int i = 0; i < col; i++)
  {
    if (seed & (1 << i))
    {
      flip++;
      candidate[0][col - i - 1] = 1;
      change(0, col - i - 1);
    }
  }

  for (int i = 1; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (toggle[i - 1][j])
      {
        flip++;
        candidate[i][j] = 1;
        change(i, j);
      }
    }
  }

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (toggle[i][j])
        return false;
    }
  }

  bool ret = false;
  if (flip < min_flip)
  {
    min_flip = flip;
    ret = true;
  }

  return ret;
}

int main(void)
{
  fastio;

  bool solve = false;
  cin >> row >> col;
  board.resize(row, vector<int>(col));
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
      cin >> board[i][j];
  }

  for (int i = 0; i < (1 << col); i++)
  {
    if (check(i))
    {
      ans = candidate;
      solve = true;
    }
  }

  if (solve)
  {
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
        cout << ans[i][j] << ' ';
      cout << endl;
    }
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}