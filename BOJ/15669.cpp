/**
 * @file 15669.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Tree + DP
 * @version 0.1
 * @date 2022-02-03
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

int n, query;
long long depth[100001], dp[100001][2];
vector<vector<int>> tree;

void dfs(int cur, int root)
{
  dp[cur][depth[cur] % 2]++;
  for (auto &&child : tree[cur])
  {
    if (child == root)
      continue;
    depth[child] = depth[cur] + 1;
    dfs(child, cur);
    dp[cur][0] += dp[child][0];
    dp[cur][1] += dp[child][1];
  }
}

int main(void)
{
  fastio;

  cin >> n >> query;
  tree.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(1, 0);

  for (int i = 0; i < query; i++)
  {
    int u, v, c;
    long long ans = 0;
    cin >> u >> v >> c;
    if(depth[u] < depth[v])
      swap(u, v);

    long long sub_even = dp[u][0], sub_odd = dp[u][1];
    long long root_even = dp[1][0] - sub_even, root_odd = dp[1][1] - sub_odd;

    if (c) 
      ans = sub_even * root_odd + sub_odd * root_even;
    else
      ans = sub_even * root_even + sub_odd * root_odd;

    cout << ans << endl;
  }

  return 0;
}