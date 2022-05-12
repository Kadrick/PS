/**
 * @file 2638.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-05-12 09:09
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

int n, m, ans;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool inRange(int y, int x)
{
  return 0 <= y && y < n && 0 <= x && x < m;
}

queue<pair<int, int>> findSide()
{
  visited.clear();
  visited.resize(n, vector<bool>(m, false));

  queue<pair<int, int>> q, side;
  visited[0][0] = true;
  q.push({0, 0});

  // find cheese side
  while (q.size())
  {
    auto here = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = here.first + dy[i];
      int nx = here.second + dx[i];

      if (!inRange(ny, nx))
        continue;

      if (visited[ny][nx])
        continue;

      visited[ny][nx] = true;
      if (board[ny][nx] == 1)
        side.push({ny, nx});
      else
        q.push({ny, nx});
    }
  }
  return side;
}

void fillHole()
{
  // fill hole
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && board[i][j] == 0)
        board[i][j] = 2;
      if (visited[i][j] && board[i][j] == 2)
        board[i][j] = 0;
    }
  }
}

void melt(queue<pair<int, int>> &side)
{
  queue<pair<int, int>> del;
  while (side.size())
  {
    auto here = side.front();
    side.pop();

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
      int ny = here.first + dy[i];
      int nx = here.second + dx[i];

      if (board[ny][nx] == 0)
        cnt++;
    }

    if (cnt >= 2)
      del.push({here.first, here.second});
  }

  while (del.size())
  {
    board[del.front().first][del.front().second] = 0;
    del.pop();
  }
}

int main(void)
{
  fastio;

  cin >> n >> m;
  board.resize(n, vector<int>(m, -1));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  }

  queue<pair<int, int>> side = findSide();
  fillHole();

  while (side.size())
  {
    ans++;

    melt(side);
    side = findSide();
    fillHole();
  }

  cout << ans << endl;

  return 0;
}