/***********************************
> File Name: 14442.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/11 17:45
> Description: BFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define dist first
#define state second
#define pos first
#define drill second
#define y first
#define x second

int n, m, k;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

char board[1001][1001];
bool isVisited[1001][1001][11];

bool inRange(int y, int x)
{
  return 1 <= y && y <= n &&
         1 <= x && x <= m;
}

int bfs()
{
  int ret = -1;

  queue<pair<int, pair<pair<int, int>, int>>> q;
  q.push({1, {{1, 1}, 0}});
  for (int i = 0; i < 11; i++)
    isVisited[1][1][i] = true;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();

    if (here.state.pos == pair<int, int>(n, m))
    {
      ret = here.dist;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int movey = here.state.pos.y + dy[i];
      int movex = here.state.pos.x + dx[i];

      if (!inRange(movey, movex))
        continue;

      if (board[movey][movex] == '0' && !isVisited[movey][movex][here.state.drill])
      {
        q.push({here.dist + 1, {{movey, movex}, here.state.drill}});
        isVisited[movey][movex][here.state.drill] = true;
      }
      else if (board[movey][movex] == '1' &&
               here.state.drill < k && !isVisited[movey][movex][here.state.drill + 1])
      {
        q.push({here.dist + 1, {{movey, movex}, here.state.drill + 1}});
        isVisited[movey][movex][here.state.drill + 1] = true;
      }
    }
  }

  return ret;
}

int main(void)
{
  fastio;

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i + 1][j + 1];
  }

  cout << bfs();

  return 0;
}