/***********************************
> File Name: 16946.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 19:26
> Description: BFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define y first
#define x second

int n, m;
char board[1001][1001];
pair<int, int> area[1001][1001];
bool isVisited[1001][1001];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

bool inRange(int y, int x)
{
  return 1 <= y && y <= n && 1 <= x && x <= m;
}

int bfs(int y, int x)
{
  int ret = 0;
  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();
    ret++;

    for (int i = 0; i < 4; i++)
    {
      int my = here.y + dy[i];
      int mx = here.x + dx[i];

      if (!inRange(my, mx))
        continue;
      if (board[my][mx] == '0' && !isVisited[my][mx])
      {
        isVisited[my][mx] = true;
        q.push({my, mx});
      }
    }
  }
  return ret;
}

void fill(int y, int x, int value, int id)
{
  queue<pair<int, int>> q;
  q.push({y, x});
  area[y][x] = {value, id};

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int my = here.y + dy[i];
      int mx = here.x + dx[i];

      if (!inRange(my, mx))
        continue;
      if (board[my][mx] == '0' && area[my][mx].first == 0)
      {
        area[my][mx] = {value, id};
        q.push({my, mx});
      }
    }
  }
}

int sum(int y, int x)
{
  int ret = 0;
  set<pair<int, int>> s;
  for (int i = 0; i < 4; i++)
  {
    int my = y + dy[i];
    int mx = x + dx[i];

    if (!inRange(my, mx))
      continue;

    s.insert(area[my][mx]);
  }

  for (auto &add : s)
    ret += add.first;

  return ret;
}

int main(void)
{
  fastio;

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> board[i + 1][j + 1];
  }

  memset(isVisited, false, sizeof(isVisited));
  int id = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i + 1][j + 1] == '0' && !isVisited[i + 1][j + 1])
      {
        int count = bfs(i + 1, j + 1);
        fill(i + 1, j + 1, count, id++);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i + 1][j + 1] == '1')
        cout << ((sum(i + 1, j + 1) + 1) % 10);
      else
        cout << "0";
    }
    cout << endl;
  }

  return 0;
}