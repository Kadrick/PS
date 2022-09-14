/***********************************
> File Name: 1976.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/28 19:41
> Description: disjoint set
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
bool path[201][201], isVisited[201];
int parent[201], tour[1001];

int find(int target)
{
  if (parent[target] == target)
    return target;
  return parent[target] = find(parent[target]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u != v)
    parent[v] = u;
}

void dfs(int here)
{
  isVisited[here] = true;

  for (int i = 1; i <= n; i++)
  {
    if (path[here][i] && !isVisited[i])
    {
      merge(here, i);
      dfs(i);
    }
  }
}

int main(void)
{
  fastio;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    for (int j = 1; j <= n; j++)
      cin >> path[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    if (isVisited[i + 1])
      continue;
    dfs(i + 1);
  }

  for (int i = 0; i < m; i++)
    cin >> tour[i];

  int hold = find(tour[0]);
  bool isFind = false;
  for (int i = 0; i < m; i++)
  {
    if (hold == find(tour[i]))
      continue;
    isFind = true;
    break;
  }

  if (isFind)
    cout << "NO";
  else
    cout << "YES";

  return 0;
}