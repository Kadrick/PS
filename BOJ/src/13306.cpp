/**
 * @file 13306.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief offline query + union find
 * @version 0.1
 * @date 2022-01-22 15:29
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

int n, q;
int parent[200001];
int root[200001];
vector<string> ans;
vector<vector<int>> queries;

int find(int here)
{
  if (here == parent[here])
    return here;
  return parent[here] = find(parent[here]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  if (u > v)
    swap(u, v);
  parent[u] = v;
}

int main(void)
{
  fastio;

  cin >> n >> q;
  for (int i = 0; i < n; i++)
    parent[i] = i;

  root[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    int tmp;
    cin >> tmp;
    root[i] = tmp;
  }

  for (int i = 0; i < n - 1 + q; i++)
  {
    int order;
    vector<int> query;
    cin >> order;
    query.push_back(order);

    if (order)
    {
      int u, v;
      cin >> u >> v;
      query.push_back(u);
      query.push_back(v);
    }
    else
    {
      int cut;
      cin >> cut;
      query.push_back(cut);
    }

    queries.push_back(query);
  }

  reverse(queries.begin(), queries.end());

  for (int i = 0; i < queries.size(); i++)
  {
    if (queries[i][0])
    {
      if (find(queries[i][1]) == find(queries[i][2]))
        ans.push_back("YES");
      else
        ans.push_back("NO");
    }
    else
      merge(queries[i][1], root[queries[i][1]]);
  }

  reverse(ans.begin(), ans.end());

  for (auto &&str : ans)
    cout << str << endl;

  return 0;
}