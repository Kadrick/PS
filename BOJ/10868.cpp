/***********************************
> File Name: 10868.cpp
> Author: Kadrick
> Created Time: 2021/10/05 13:48
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

pair<long long, long long> init(vector<long long> &arr, vector<pair<long long, long long>> &tree,
                                int here, int start, int end)
{
  if (start == end)
    return tree[here] = {arr[start], arr[start]};

  auto l = init(arr, tree, here * 2, start, (start + end) / 2);
  auto r = init(arr, tree, here * 2 + 1, (start + end) / 2 + 1, end);
  return tree[here] = {max(l.first, r.first), min(l.second, r.second)};
}

pair<long long, long long> getMM(vector<pair<long long, long long>> &tree,
                                 int here, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return {-9876543210, 9876543210};
  if (left <= start && end <= right)
    return tree[here];

  auto l = getMM(tree, here * 2, start, (start + end) / 2, left, right);
  auto r = getMM(tree, here * 2 + 1, (start + end) / 2 + 1, end, left, right);

  return {max(l.first, r.first), min(l.second, r.second)};
}

int main(void)
{
  fastio;

  int n, m, b, h, treeSize, c;
  vector<long long> arr;
  vector<pair<long long, long long>> tree;

  cin >> n >> m;
  arr.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  h = (int)ceil(log2(n));
  treeSize = (1 << (h + 1));

  tree.resize(treeSize);

  init(arr, tree, 1, 0, n - 1);

  for (int i = 0; i < m; ++i)
  {
    cin >> b >> c;
    auto ret = getMM(tree, 1, 0, n - 1, b - 1, c - 1);
    cout << ret.second << endl;
  }

  return 0;
}