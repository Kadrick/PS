/***********************************
> File Name: 11505.cpp
> Author: Kadrick
> Created Time: 2021/10/04 17:11
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'
#define MOD 1000000007

/* 
> arr: array
> tree: segment tree
> here: current node number
> start, end: range
*/
long long init(vector<long long> &arr, vector<long long> &tree,
               int here, int start, int end)
{
  if (start == end)
    return tree[here] = arr[start];
  return tree[here] =
             (init(arr, tree, here * 2, start, (start + end) / 2) *
              init(arr, tree, here * 2 + 1, (start + end) / 2 + 1, end)) %
             MOD;
}

/* 
> tree: segment tree
> here: current node number
> start, end: range
> index: update position
> diff: update value
*/
long long update(vector<long long> &tree,
                 int here, int start, int end, int index, int diff)
{
  if (index > end || index < start)
    return tree[here];

  if (start == end)
    return tree[here] = diff;

  return tree[here] = (update(tree, here * 2, start, (start + end) / 2, index, diff) *
                       update(tree, here * 2 + 1, (start + end) / 2 + 1, end, index, diff)) %
                      MOD;
}

/* 
> tree: segment tree
> here: current node number
> start, end: range
> left, right: wanted
*/
long long getTimes(vector<long long> &tree,
                   int here, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return 1;
  if (left <= start && end <= right)
    return tree[here];

  return (getTimes(tree, here * 2, start, (start + end) / 2, left, right) *
          getTimes(tree, here * 2 + 1, (start + end) / 2 + 1, end, left, right)) %
         MOD;
}

int main(void)
{
  fastio;

  int n, m, k, a, b, h, treeSize, c;
  vector<long long> arr;
  vector<long long> tree;

  cin >> n >> m >> k;
  arr.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  h = (int)ceil(log2(n));
  treeSize = (1 << (h + 1));

  tree.resize(treeSize);

  init(arr, tree, 1, 0, n - 1);

  for (int i = 0; i < m + k; ++i)
  {
    cin >> a >> b >> c;
    if (a == 1)
    {
      update(tree, 1, 0, n - 1, b - 1, c);
    }
    else if (a == 2)
      cout << getTimes(tree, 1, 0, n - 1, b - 1, c - 1) << endl;
  }

  return 0;
}