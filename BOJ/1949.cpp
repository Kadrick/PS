/***********************************
> File Name: 1949.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/07 15:14
> Description: DP on tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
int arr[10001];
int dp[10001][2];
vector<int> adj[10001];
vector<int> tree[10001];

int solve(int here, bool goodCity) {
  if(tree[here].empty()) {
    return goodCity ? arr[here] : 0;
  }

  int& ret= dp[here][goodCity];
  if (ret != -1)
    return ret;
  
  ret = 0;
  
  if(goodCity) {
    ret = arr[here];
    for(auto& child : tree[here]) {
      ret += solve(child, false); 
    }
  } else {
    for(auto& child : tree[here])
      ret += max(solve(child, true), solve(child, false)); 
  }
  
  return ret;
}

void makeTree(int here, int root) {
  if(root != -1) tree[root].push_back(here);
  
  for(auto& child : adj[here]){
    if(child == root) continue;
    makeTree(child, here);
  }
}

int main(void) {
  fastio;

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i + 1];

  
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  makeTree(1, -1);

  cout << max(solve(1, true), solve(1, false));

  return 0;
}