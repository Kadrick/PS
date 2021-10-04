/***********************************
> File Name: 2042.cpp
> Author: Kadrick
> Created Time: 2021/09/16 13:46
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

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
             init(arr, tree, here * 2, start, (start + end) / 2) +
             init(arr, tree, here * 2 + 1, (start + end) / 2 + 1, end);
}

/* 
> tree: segment tree
> here: current node number
> start, end: range
> index: update position
> diff: update value
*/
void update(vector<long long> &tree,
            int here, int start, int end, int index, long long diff)
{
  // out of range
  if (index < start || index > end)
    return;

  tree[here] += diff;

  if (start != end)
  {
    update(tree, here * 2, start, (start + end) / 2, index, diff);
    update(tree, here * 2 + 1, (start + end) / 2 + 1, end, index, diff);
  }
}

/* 
> tree: segment tree
> here: current node number
> start, end: range
> left, right: wanted
*/
long long getSum(vector<long long> &tree,
                 int here, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return 0;
  if (left <= start && end <= right)
    return tree[here];

  return getSum(tree, here * 2, start, (start + end) / 2, left, right) +
         getSum(tree, here * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
  fastio;

  int n, m, k, a, b, h, treeSize;
  long long c;
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
      b--;
      long long diff = c - arr[b];
      arr[b] = c;
      update(tree, 1, 0, n - 1, b, diff);
    }
    else if (a == 2)
      cout << getSum(tree, 1, 0, n - 1, b - 1, c - 1) << endl;
  }

  return 0;
}