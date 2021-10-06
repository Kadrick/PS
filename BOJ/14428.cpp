/***********************************
> File Name: 14428.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/05 21:58
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m, h, treeSize;
vector<pair<int, int>> arr;
vector<pair<int, int>> tree;

pair<int, int> init(int here, int start, int end)
{
  if (start == end)
    return tree[here] = arr[start];
  return tree[here] = min(
             init(here * 2, start, (start + end) / 2),
             init(here * 2 + 1, (start + end) / 2 + 1, end));
}

pair<int, int> update(int here, int start, int end, int idx, int diff)
{
  if (idx > end || idx < start)
    return tree[here];
  if (start == end)
    return tree[here] = {diff, idx};
  return tree[here] = min(
             update(here * 2, start, (start + end) / 2, idx, diff),
             update(here * 2 + 1, (start + end) / 2 + 1, end, idx, diff));
}

pair<int, int> getM(int here, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return {2100000000, 210000000};
  if (left <= start && end <= right)
    return tree[here];

  return min(
      getM(here * 2, start, (start + end) / 2, left, right),
      getM(here * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
  fastio;

  cin >> n;
  h = (int)ceil(log2(n));
  treeSize = (1 << (h + 1));
  arr.resize(n);
  tree.resize(treeSize);

  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    arr[i] = {input, i};
  }

  init(1, 0, n - 1);

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int order;
    cin >> order;
    if (order == 1)
    {
      // update
      int pos, value;
      cin >> pos >> value;
      pos--;
      update(1, 0, n - 1, pos, value);
    }
    else if (order == 2)
    {
      // find min
      int left, right;
      cin >> left >> right;
      cout << getM(1, 0, n - 1, left - 1, right - 1).second + 1 << endl;
    }
  }

  return 0;
}