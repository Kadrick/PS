/**
 * @file 1795.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-03-06 20:03
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

int n, m, horse, ans = INT_MAX;
vector<string> board;
vector<vector<pair<int, int>>> cnt;

int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool inRange(int y, int x)
{
  return (0 <= y && y < n && 0 <= x && x < m);
}

void bfs(int y, int x, int jump)
{
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {y, x}});
  visited[y][x] = true;

  while (q.size())
  {
    auto here = q.front();
    q.pop();

    auto &pos = here.second;

    cnt[pos.first][pos.second].first++;
    cnt[pos.first][pos.second].second += here.first ? (here.first - 1) / jump + 1 : 0;

    for (int i = 0; i < 8; i++)
    {
      int ny = pos.first + dy[i];
      int nx = pos.second + dx[i];

      if (!inRange(ny, nx) || visited[ny][nx])
        continue;

      visited[ny][nx] = true;
      q.push({here.first + 1, {ny, nx}});
    }
  }
}

int main(void)
{
  fastio;

  cin >> n >> m;
  cnt.resize(n, vector<pair<int, int>>(m, {0, 0}));
  for (int i = 0; i < n; i++)
  {
    string row;
    cin >> row;
    board.push_back(row);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] != '.')
      {
        horse++;
        bfs(i, j, board[i][j] - '0');
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (cnt[i][j].first == horse)
        ans = min(ans, cnt[i][j].second);
    }
  }

  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}