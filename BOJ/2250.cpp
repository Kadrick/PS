/**
 * @file 2250.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief DFS -> inorder
 * @version 0.1
 * @date 2022-01-20 16:08
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

int n, cnt;
vector<pair<int, int>> ans;
vector<int> degree;
vector<vector<int>> tree;

void in_order(int lv, int root)
{
  if (root == -1)
    return;

  in_order(lv + 1, tree[root][0]);
  cnt++;
  if (!ans[lv].first)
    ans[lv].first = cnt;
  else
    ans[lv].second = cnt;
  in_order(lv + 1, tree[root][1]);
}

int main(void)
{
  fastio;

  cin >> n;
  ans.resize(n + 1, {0, 0});
  degree.resize(n + 1, 0);
  tree.resize(n + 1, vector<int>(2, -1));
 
  for (int i = 0; i < n; i++)
  {
    int root, left, right;
    cin >> root >> left >> right;
    tree[root][0] = left;
    tree[root][1] = right;
    if(left != -1) degree[left] += 1;
    if(right != -1) degree[right] += 1;
  }

  for (int i = 0; i < n; i++)
  {
    if (!degree[i + 1])
    {
      in_order(1, i + 1);
      break;
    }
  }

  int lv = 1, width = 1;
  for (int i = 0; i < n; i++)
  {
    if (ans[i + 1].second - ans[i + 1].first + 1 > width)
    {
      width = ans[i + 1].second - ans[i + 1].first + 1;
      lv = i + 1;
    }
  }

  cout << lv << ' ' << width;

  return 0;
}