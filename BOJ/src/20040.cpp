/***********************************
> File Name: 20040.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/05 21:46
> Description: disjoint set
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
int parent[500001];

int find(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
  if (v > u)
    swap(u, v);
  u = find(u);
  v = find(v);
  if (u != v)
  {
    parent[v] = u;
    return true;
  }
  return false;
}

int main(void)
{
  fastio;

  for (int i = 0; i < 500001; i++)
    parent[i] = i;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    if (!merge(u, v))
    {
      cout << i + 1;
      return 0;
    }
  }

  cout << 0;

  return 0;
}