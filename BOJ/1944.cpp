/**
 * @file 1944.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief MST + BFS
 * @version 0.1
 * @date 2022-01-27 17:00
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

int n, k, cnt_node, ans;
vector<string> board;
vector<pair<int, int>> dup_pos;
vector<vector<int>> board_node;

typedef struct _Edge
{
  int start;
  int end;
  int cost;
  _Edge(int u, int v, int m)
  {
    start = u;
    end = v;
    cost = m;
  }
} Edge;

bool comp(const Edge &left, const Edge &right)
{
  return left.cost < right.cost;
}

vector<int> parent;
vector<Edge> edges;

int Find(int v)
{
  if (parent[v] == v)
    return v;
  else
    return parent[v] = Find(parent[v]);
}

bool Union(int start, int end)
{
  start = Find(start);
  end = Find(end);
  if (start != end)
  {
    parent[start] = end;
    return true;
  }

  return false;
}

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool bfs(int here)
{
  int access = 0;
  queue<pair<int, pair<int, int>>> q;
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  q.push({1, dup_pos[here]});
  visited[q.front().second.first][q.front().second.second] = true;

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = front.second.first + dy[i];
      int nx = front.second.second + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n)
        continue;
      if (visited[ny][nx] || board[ny][nx] == '1')
        continue;
      if (board[ny][nx] == 'S' || board[ny][nx] == 'K')
      {
        edges.push_back(Edge(here, board_node[ny][nx], front.first));
        access++;
      }
      visited[ny][nx] = true;
      q.push({front.first + 1, {ny, nx}});
    }
  }

  return access == k;
}

int main(void)
{
  fastio;

  cin >> n >> k;
  board.resize(n, "");
  board_node.resize(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++)
    cin >> board[i];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] == 'S' || board[i][j] == 'K')
      {
        dup_pos.push_back({i, j});
        board_node[i][j] = cnt_node++;
      }
    }
  }

  for (int i = 0; i < dup_pos.size(); i++)
  {
    if (!bfs(i))
    {
      cout << "-1" << endl;
      return 0;
    }
  }

  parent.resize(cnt_node, -1);
  for (int i = 0; i < cnt_node; i++)
    parent[i] = i;

  sort(edges.begin(), edges.end(), comp);

  for (auto &e : edges)
  {
    if (Union(e.start, e.end))
      ans += e.cost;
  }

  cout << ans << endl;

  return 0;
}