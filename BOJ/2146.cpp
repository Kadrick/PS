/**
 * @file 2146.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-05-04 10:51
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

int n, ans = INT32_MAX;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<int>> plain_board;

bool in_range(int y, int x)
{
  return 0 <= y && y < n && 0 <= x && x < n;
}

void print_board(vector<vector<int>> &b)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << b[i][j] << ' ';
    cout << endl;
  }
}

void make_island(int id, int y, int x)
{
  queue<pair<int, int>> q;
  q.push({y, x});
  board[y][x] = id;
  visited[y][x] = true;

  while (q.size())
  {
    auto here = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = here.first + dy[i];
      int nx = here.second + dx[i];

      if (!in_range(ny, nx) || visited[ny][nx])
        continue;

      if (plain_board[ny][nx] == 0)
        continue;

      board[ny][nx] = id;
      visited[ny][nx] = true;
      q.push({ny, nx});
    }
  }
}

int find_path(int y, int x, int id)
{
  int ret = INT32_MAX;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (in_range(ny, nx) && board[ny][nx] == 0)
    {
      visited.clear();
      visited.resize(n, vector<bool>(n, false));
      visited[ny][nx] = true;
      queue<pair<int, pair<int, int>>> q;
      q.push({0, {ny, nx}});

      while (q.size())
      {
        auto here = q.front();
        q.pop();

        if (board[here.second.first][here.second.second] != 0)
        {
          ret = min(ret, here.first);
          break;
        }

        for (int j = 0; j < 4; j++)
        {
          int my = here.second.first + dy[j];
          int mx = here.second.second + dx[j];

          if (!in_range(my, mx) || visited[my][mx])
            continue;

          if (board[my][mx] == id)
            continue;

          q.push({here.first + 1, {my, mx}});
          visited[my][mx] = true;
        }
      }
    }
  }

  return ret;
}

int main(void)
{
  fastio;

  cin >> n;
  board.resize(n, vector<int>(n, 0));
  plain_board.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> plain_board[i][j];
  }

  int id = 1;
  visited.resize(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (plain_board[i][j] == 1 && !visited[i][j])
        make_island(id++, i, j);
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] != 0)
        ans = min(ans, find_path(i, j, board[i][j]));
    }
  }

  cout << ans << endl;

  return 0;
}