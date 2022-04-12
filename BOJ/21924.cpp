/**
 * @file 21924.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-04-12 12:55
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

int n, m;
long long total;
vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int find(int root)
{
  if (root == parent[root])
    return root;
  return parent[root] = find(parent[root]);
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return false;

  if (u > v)
    swap(u, v);

  parent[v] = u;
  return true;
}

int main(void)
{
  fastio;

  cin >> n >> m;
  parent.resize(n + 1);

  for (int i = 0; i <= n; i++)
    parent[i] = i;

  for (int i = 0; i < m; i++)
  {
    int u, v, c;
    cin >> u >> v >> c;
    total += c;

    edges.push_back({c, {u, v}});
  }

  sort(edges.begin(), edges.end());

  int cnt = 0;
  long long mst = 0;
  for (int i = 0; i < m; i++)
  {
    if (merge(edges[i].second.first, edges[i].second.second))
    {
      cnt++;
      mst += edges[i].first;
    }

    if (cnt == n - 1)
      break;
  }

  if (cnt == n - 1)
    cout << total - mst << endl;
  else
    cout << -1 << endl;

  return 0;
}