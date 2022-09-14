/***********************************
> File Name: 13913.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/29 00:53
> Description: BFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define pos first
#define time second

int n, k, ans;
bool isVisited[100001];
int parent[100001];

void print(int here)
{
  if (parent[here] != -1)
    print(parent[here]);
  cout << here << ' ';
}

bool inRange(int p)
{
  return 0 <= p && p <= 100000;
}

void bfs()
{
  queue<pair<int, int>> q;
  q.push({n, 0});
  isVisited[n] = true;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();

    if (here.pos == k)
    {
      ans = here.time;
      break;
    }

    if (inRange(here.pos + 1) && !isVisited[here.pos + 1])
    {
      parent[here.pos + 1] = here.pos;
      isVisited[here.pos + 1] = true;
      q.push({here.pos + 1, here.time + 1});
    }

    if (inRange(here.pos - 1) && !isVisited[here.pos - 1])
    {
      parent[here.pos - 1] = here.pos;
      isVisited[here.pos - 1] = true;
      q.push({here.pos - 1, here.time + 1});
    }

    if (inRange(here.pos * 2) && !isVisited[here.pos * 2])
    {
      parent[here.pos * 2] = here.pos;
      isVisited[here.pos * 2] = true;
      q.push({here.pos * 2, here.time + 1});
    }
  }
}

int main(void)
{
  fastio;

  cin >> n >> k;
  memset(parent, -1, sizeof(parent));

  bfs();

  cout << ans << endl;
  print(k);

  return 0;
}