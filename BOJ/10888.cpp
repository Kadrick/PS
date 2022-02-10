/**
 * @file 10888.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math + disjoint set
 * @version 0.1
 * @date 2022-02-10 12:57
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
#define int long long

int n;
vector<int> parent, sz;

int find(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u != v)
  {
    if (u < v)
      swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return;
  }
  return;
}

int find_pair(int n)
{
  return n * (n - 1) / 2; // pair cnt
}

// 1 + (1 + 2) + (1 + 2 + 3) ...
int find_sum(int n)
{
  return n * (n - 1) * (n + 1) / 6;
}

int32_t main(void)
{
  fastio;

  cin >> n;
  parent.resize(n + 1);
  sz.resize(n + 1, 1);

  for (int i = 0; i <= n; i++)
    parent[i] = i;

  int a1 = 0, a2 = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int u;
    cin >> u;

    int a, b;
    a = find(u);
    b = find(u + 1);

    if (a != b)
    {
      a1 -= find_pair(sz[a]) + find_pair(sz[b]);
      a2 -= find_sum(sz[a]) + find_sum(sz[b]);

      merge(a, b);

      a = find(a);
      a1 += find_pair(sz[a]);
      a2 += find_sum(sz[a]);
    }
    cout << a1 << ' ' << a2 << endl;
  }

  return 0;
}