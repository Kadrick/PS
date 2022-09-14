/**
 * @file 14868.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS + disjoint set
 * @version 0.1
 * @date 2022-03-07 19:08
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

int n, k, ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> parent;
vector<vector<int>> board;
queue<pair<int, int>> before, after;

int find(int here)
{
  if (parent[here] == here)
    return here;
  return parent[here] = find(parent[here]);
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return false;

  if (v < u)
    swap(u, v);

  parent[v] = u;
  return true;
}

bool inRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < n;
}

int main(void)
{
  fastio;

  cin >> n >> k;
  parent.resize(n * n + 1, 0);
  for (int i = 0; i <= n * n; i++)
    parent[i] = i;

  board.resize(n, vector<int>(n, 0));
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    board[x - 1][y - 1] = i + 1;
    before.push({x - 1, y - 1});
  }

  while (true)
  {
    while (before.size())
    {
      auto here = before.front();
      before.pop();
      after.push(here);

      for (int i = 0; i < 4; i++)
      {
        int nx = here.first + dx[i];
        int ny = here.second + dy[i];

        if (!inRange(nx, ny))
          continue;

        if (board[nx][ny] != 0)
        {
          bool check = merge(board[here.first][here.second],
                             board[nx][ny]);
          if (check)
            k--;
        }
      }
    }
    if (k == 1)
      break;
    while (after.size())
    {
      auto here = after.front();
      after.pop();

      for (int i = 0; i < 4; i++)
      {
        int nx = here.first + dx[i];
        int ny = here.second + dy[i];

        if (!inRange(nx, ny))
          continue;

        if (board[nx][ny] == 0)
        {
          before.push({nx, ny});
          board[nx][ny] = board[here.first][here.second];
        }
      }
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}