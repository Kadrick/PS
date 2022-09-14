/**
 * @file 1799.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief backtracking
 * @version 0.1
 * @date 2022-05-20 13:46
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

int n, ans_white, ans_black;
bool visited[10][10];
vector<pair<int, int>> bishop_white_possible, bishop_black_possible;

bool checkPlace(int y, int x)
{
  for (int i = 1; i <= y; i++)
  {
    if (x - i >= 0)
    {
      if (visited[y - i][x - i])
        return false;
    }
    if (x + i < n)
    {
      if (visited[y - i][x + i])
        return false;
    }
  }
  return true;
}

void solve_white(int idx, int cnt)
{
  if (idx == bishop_white_possible.size())
  {
    ans_white = max(ans_white, cnt);
    return;
  }

  int y, x;
  tie(y, x) = bishop_white_possible[idx];
  if (checkPlace(y, x))
  {
    visited[y][x] = true;
    solve_white(idx + 1, cnt + 1);
    visited[y][x] = false;
  }
  solve_white(idx + 1, cnt);
}

void solve_black(int idx, int cnt)
{
  if (idx == bishop_black_possible.size())
  {
    ans_black = max(ans_black, cnt);
    return;
  }

  int y, x;
  tie(y, x) = bishop_black_possible[idx];
  if (checkPlace(y, x))
  {
    visited[y][x] = true;
    solve_black(idx + 1, cnt + 1);
    visited[y][x] = false;
  }
  solve_black(idx + 1, cnt);
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int possible;
      cin >> possible;
      if (possible)
      {
        if ((i + j) % 2)
          bishop_white_possible.push_back({i, j});
        else
          bishop_black_possible.push_back({i, j});
      }
    }
  }

  solve_white(0, 0);
  solve_black(0, 0);

  cout << ans_white + ans_black << endl;

  return 0;
}