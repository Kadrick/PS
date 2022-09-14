/**
 * @file 14500.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2021-12-18 21:46
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long n, m, INF = -1e9, ans;
vector<vector<long long>> board;

bool inRange(long long y, long long x)
{
  return 0 <= y && y < n && 0 <= x && x < m;
}

//////////////////////////////////
/* block */

// I-mino
long long getI_h(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 4; i++)
  {
    if (inRange(y, x + i))
      ret += board[y][x + i];
    else
    {
      ret += INF;
      break;
    }
  }

  return ret;
}

long long getI_v(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 4; i++)
  {
    if (inRange(y + i, x))
      ret += board[y + i][x];
    else
    {
      ret += INF;
      break;
    }
  }

  return ret;
}

/* O-mino */
long long getO(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 2; i++)
  {
    for (long long j = 0; j < 2; j++)
    {
      if (inRange(y + i, x + j))
        ret += board[y + i][x + j];
      else
      {
        ret += INF;
        break;
      }
    }
  }

  return ret;
}

/* Z-mino*/
long long getZ_h(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 2; i++)
  {
    for (long long j = 0; j < 2; j++)
    {
      if (inRange(y + i, x + j + i))
        ret += board[y + i][x + j + i];
      else
      {
        ret += INF;
        break;
      }
    }
  }

  return ret;
}

long long getZ_v(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 2; i++)
  {
    for (long long j = 0; j < 2; j++)
    {
      if (inRange(y + i + j, x - i))
        ret += board[y + i + j][x - i];
      else
      {
        ret += INF;
        break;
      }
    }
  }

  return ret;
}

/* s-mino */
long long getS_v(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 2; i++)
  {
    for (long long j = 0; j < 2; j++)
    {
      if (inRange(i + j + y, x + i))
        ret += board[i + j + y][x + i];
      else
      {
        ret += INF;
        break;
      }
    }
  }

  return ret;
}

long long getS_h(long long y, long long x)
{
  long long ret = 0;

  for (long long i = 0; i < 2; i++)
  {
    for (long long j = 0; j < 2; j++)
    {
      if (inRange(y - i, x + i + j))
        ret += board[y - i][x + i + j];
      else
      {
        ret += INF;
        break;
      }
    }
  }

  return ret;
}

/* J-mino */
long long getJ_h(long long y, long long x)
{
  long long left = 0, right = 0;

  for (long long i = 0; i < 3; i++)
  {
    if (inRange(y, x + i))
      left += board[y][x + i];
    else
      left += INF;
    if (inRange(y, x - i))
      right += board[y][x - i];
    else
      right += INF;
  }
  if (inRange(y + 1, x + 2))
    left += board[y + 1][x + 2];
  else
    left += INF;
  if (inRange(y - 1, x - 2))
    right += board[y - 1][x - 2];
  else
    right += INF;

  return max(left, right);
}

long long getJ_v(long long y, long long x)
{
  long long up = 0, down = 0;

  for (long long i = 0; i < 3; i++)
  {
    if (inRange(y + i, x))
      down += board[y + i][x];
    else
      down += INF;
    if (inRange(y - i, x))
      up += board[y - i][x];
    else
      up += INF;
  }
  if (inRange(y + 2, x - 1))
    down += board[y + 2][x - 1];
  else
    down += INF;
  if (inRange(y - 2, x + 1))
    up += board[y - 2][x + 1];
  else
    up += INF;

  return max(up, down);
}

/* L-mino */
long long getL_h(long long y, long long x)
{
  long long left = 0, right = 0;

  for (long long i = 0; i < 3; i++)
  {
    if (inRange(y, x + i))
      left += board[y][x + i];
    else
      left += INF;
    if (inRange(y, x - i))
      right += board[y][x - i];
    else
      right += INF;
  }
  if (inRange(y - 1, x + 2))
    left += board[y - 1][x + 2];
  else
    left += INF;
  if (inRange(y + 1, x - 2))
    right += board[y + 1][x - 2];
  else
    right += INF;

  return max(left, right);
}

long long getL_v(long long y, long long x)
{
  long long up = 0, down = 0;

  for (long long i = 0; i < 3; i++)
  {
    if (inRange(y + i, x))
      down += board[y + i][x];
    else
      down += INF;
    if (inRange(y - i, x))
      up += board[y - i][x];
    else
      up += INF;
  }
  if (inRange(y + 2, x + 1))
    down += board[y + 2][x + 1];
  else
    down += INF;
  if (inRange(y - 2, x - 1))
    up += board[y - 2][x - 1];
  else
    up += INF;

  return max(up, down);
}

long long getT(long long y, long long x)
{
  long long up = 0, down = 0, left = 0, right = 0;
  for (long long i = 0; i < 3; i++)
  {
    if (inRange(y, x + i))
    {
      up += board[y][x + i];
      down += board[y][x + i];
    }
    else
    {
      up += INF;
      down += INF;
    }
    if (inRange(y + i, x))
    {
      left += board[y + i][x];
      right += board[y + i][x];
    }
    else
    {
      left += INF;
      right += INF;
    }
  }

  // up
  if (inRange(y - 1, x + 1))
    up += board[y - 1][x + 1];
  else
    up += INF;

  // down
  if (inRange(y + 1, x + 1))
    down += board[y + 1][x + 1];
  else
    down += INF;

  // left
  if (inRange(y + 1, x - 1))
    left += board[y + 1][x - 1];
  else
    left += INF;

  // right
  if (inRange(y + 1, x + 1))
    right += board[y + 1][x + 1];
  else
    right += INF;

  return max({up, down, left, right});
}

int main(void)
{
  fastio;

  cin >> n >> m;
  board.resize(n, vector<long long>(m));

  for (long long i = 0; i < n; i++)
  {
    for (long long j = 0; j < m; j++)
      cin >> board[i][j];
  }

  for (long long i = 0; i < n; i++)
  {
    for (long long j = 0; j < m; j++)
    {
      ans = max({ans,
                 getI_h(i, j),
                 getI_v(i, j),

                 getS_h(i, j),
                 getS_v(i, j),

                 getZ_h(i, j),
                 getZ_v(i, j),

                 getJ_h(i, j),
                 getJ_v(i, j),

                 getL_h(i, j),
                 getL_v(i, j),

                 getO(i, j),

                 getT(i, j)});
    }
  }

  cout << ans << endl;

  return 0;
}