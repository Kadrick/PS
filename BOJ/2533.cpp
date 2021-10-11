/***********************************
> File Name: 2533.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/07 14:09
> Description: DP on Tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
vector<vector<int>> g;
vector<vector<int>> tree;

int dp[1000001][2];

// here is cur node, isEarly is state
int solve(int here, bool isEarly)
{
  // base case: leaf node
  if (tree[here].empty())
  {
    if (isEarly)
      return 1;
    else
      return 0;
  }

  // dp
  int &ret = dp[here][isEarly];
  if (ret != -1)
    return ret;

  ret = 0;

  if (isEarly)
  {
    ret += 1;
    for (auto &&child : tree[here])
      ret += min(solve(child, false), solve(child, true));
  }
  else
  {
    for (auto &&child : tree[here])
      ret += solve(child, true);
  }

  return ret;
}

void makeTree(int here, int root)
{
  if (root != -1)
    tree[root].push_back(here);

  for (auto &&child : g[here])
  {
    if (child == root)
      continue;
    makeTree(child, here);
  }
}

int main(void)
{
  fastio;

  cin >> n;
  g.resize(n + 1, vector<int>());
  tree.resize(n + 1, vector<int>());
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // make tree that root is 1
  makeTree(1, -1);

  cout << min(solve(1, false), solve(1, true));

  return 0;
}