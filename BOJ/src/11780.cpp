/***********************************
> File Name: 11780.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/06 20:05
> Description: FW
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
int INF = 1e9;
int dist[101][101];
int parent[101][101];

void findPath(vector<int>& path, int src, int dest)
{
  if (parent[src][dest] == 0)
  {
    path.push_back(src);
    path.push_back(dest);
    return;
  }
  findPath(path, src, parent[src][dest]);
  path.pop_back();
  findPath(path, parent[src][dest], dest);
}

void printPath(int src, int dest)
{
  vector<int> path;
  findPath(path, src, dest);
  cout << path.size() << ' ';
  for (auto &&waypoint : path)
  {
    cout << waypoint << ' ';
  }
  cout << endl;
}

int main(void)
{
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        dist[i + 1][i + 1] = 0;
      else
        dist[i + 1][j + 1] = INF;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    dist[u][v] = min(dist[u][v], c);
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          parent[i][j] = k;
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << (dist[i + 1][j + 1] == INF ? 0:dist[i + 1][j + 1]) << ' ';
    cout << endl;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        cout << 0 << endl;
      else if (dist[i][j] == INF)
        cout << 0 << endl;
      else
      {
        printPath(i, j);
      }
    }
  }

  return 0;
}