/***********************************
> File Name: 14438.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/11 21:19
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m, h, treeSize, input;
vector<int> arr;
vector<int> tree;

int init(int node, int start, int end)
{
  if (start == end)
    return tree[node] = arr[start];

  return tree[node] = min(
             init(node * 2, start, (start + end) / 2),
             init(node * 2 + 1, (start + end) / 2 + 1, end));
}

int update(int node, int start, int end, int idx, int value)
{
  if (idx < start || end < idx)
    return tree[node];

  if (start == end)
    return tree[node] = value;

  return tree[node] = min(
             update(node * 2, start, (start + end) / 2, idx, value),
             update(node * 2 + 1, (start + end) / 2 + 1, end, idx, value));
}

int getM(int node, int start, int end, int left, int right)
{
  if (start > right || end < left)
    return 1e9 + 1;
  if (left <= start && end <= right)
    return tree[node];

  return min(
      getM(node * 2, start, (start + end) / 2, left, right),
      getM(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }

  h = (int)ceil(log2(n));
  treeSize = (1 << (h + 1));
  tree.resize(treeSize);

  init(1, 0, n - 1);

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    if (input == 1)
    {
      int idx, value;
      cin >> idx >> value;
      update(1, 0, n - 1, idx - 1, value);
    }
    else if (input == 2)
    {
      int left, right;
      cin >> left >> right;
      cout << getM(1, 0, n - 1, left - 1, right - 1) << endl;
    }
  }

  return 0;
}