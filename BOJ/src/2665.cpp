/***********************************
> File Name: 2665.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/19 04:13
> Description: BFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

char input;
int n;
int board[51][51];
int visited[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inRange(int y, int x)
{
  return 1 <= y && y <= n && 1 <= x && x <= n;
}

void bfs()
{
  queue<pair<int, int>> q;
  q.push({1, 1});
  visited[1][1] = 0;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();

    int y = here.first;
    int x = here.second;

    for (int i = 0; i < 4; i++)
    {
      int movey = y + dy[i];
      int movex = x + dx[i];

      if (!inRange(movey, movex))
        continue;

      if (visited[y][x] + 1 < visited[movey][movex] && !board[movey][movex])
      {
        visited[movey][movex] = visited[y][x] + 1;
        q.push({movey, movex});
      }
      else if (visited[y][x] < visited[movey][movex] && board[movey][movex])
      {
        visited[movey][movex] = visited[y][x];
        q.push({movey, movex});
      }
    }
  }
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> input;
      board[i + 1][j + 1] = input - '0';
      visited[i + 1][j + 1] = 987654321;
    }
  }

  bfs();

  cout << visited[n][n];

  return 0;
}