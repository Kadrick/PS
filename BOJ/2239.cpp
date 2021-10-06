/***********************************
> File Name: 2239.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/05 19:43
> Description: Back tracking
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int board[9][9];
bool garo[10], sero[10], box[10];

bool jg(int y, int num)
{
  for (int i = 0; i < 9; i++)
    garo[board[y][i]] = true;

  if (garo[num])
    return false;
  return true;
}

bool js(int x, int num)
{
  for (int i = 0; i < 9; i++)
    sero[board[i][x]] = true;

  if (sero[num])
    return false;
  return true;
}

bool jbox(int y, int x, int num)
{
  y = (y / 3) * 3;
  x = (x / 3) * 3;

  for (int i = y; i < y + 3; i++)
  {
    for (int j = x; j < x + 3; j++)
      box[board[i][j]] = true;
  }

  if (box[num])
    return false;
  return true;
}

bool judge(int idx, int num)
{
  memset(garo, false, sizeof(garo));
  memset(sero, false, sizeof(sero));
  memset(box, false, sizeof(box));

  int x = idx % 9;
  int y = idx / 9;
  if (jg(y, num) && js(x, num) && jbox(y, x, num))
    return true;
  return false;
}

void print()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
      cout << board[i][j];
    cout << endl;
  }
}

bool solve(int idx)
{
  if (idx == 81)
  {
    print();
    return true;
  }

  if (board[idx / 9][idx % 9])
    return solve(idx + 1);

  bool ret = false;
  for (int i = 1; i < 10; i++)
  {
    if (judge(idx, i))
    {
      board[idx / 9][idx % 9] = i;
      ret = solve(idx + 1);
      if (ret)
        return ret;
    }
  }
  board[idx / 9][idx % 9] = 0;
  return ret;
}

int main(void)
{
  fastio;

  char input;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cin >> input;
      board[i][j] = input - '0';
    }
  }

  solve(0);

  return 0;
}