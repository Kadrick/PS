/***********************************
> File Name: 2268.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/05 14:00
> Description: seg tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<long long> arr;
vector<long long> tree;

void update(int here, int start, int end, int idx, long long diff)
{
  if (idx < start || end < idx)
    return;

  tree[here] += diff;

  if (start != end)
  {
    update(here * 2, start, (start + end) / 2, idx, diff);
    update(here * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
  }
}

long long getSum(int here, int start, int end, int left, int right)
{
  if (start > right || end < left)
    return 0;
  if (left <= start && end <= right)
    return tree[here];

  return getSum(here * 2, start, (start + end) / 2, left, right) +
         getSum(here * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
  fastio;
  cin >> n >> m;
  arr.resize(n, 0);

  int h = (int)ceil(log2(n));
  int treeSize = (1 << (h + 1));

  tree.resize(treeSize, 0);

  for (int i = 0; i < m; i++)
  {
    int order, a, b;
    cin >> order;
    if (order == 0)
    {
      //sum
      cin >> a >> b;
      if (a > b)
        swap(a, b);

      cout << getSum(1, 0, n - 1, a - 1, b - 1) << endl;
    }
    else if (order == 1)
    {
      //update
      cin >> a >> b;
      long long diff = b - arr[a - 1];
      arr[a - 1] = b;
      update(1, 0, n - 1, a - 1, diff);
    }
  }

  return 0;
}