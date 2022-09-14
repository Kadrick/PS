/**
 * @file 2517.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief segment tree
 * @version 0.1
 * @date 2022-03-07 04:57
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

int n, input;
vector<int> ability, sortAbility;
vector<long long> tree;

long long update(int here, int start, int end, int change, int diff)
{
  if (change < start || end < change)
    return tree[here];
  if (start == end)
    return tree[here] = diff;

  int mid = (start + end) >> 1;
  tree[here] = update(here * 2 + 1, start, mid, change, diff) +
               update(here * 2 + 2, mid + 1, end, change, diff);
  return tree[here];
}

long long sum(int here, int start, int end, int left, int right)
{
  if (end < left || right < start)
    return 0;
  if (left <= start && end <= right)
    return tree[here];

  int mid = (start + end) >> 1;
  return sum(here * 2 + 1, start, mid, left, right) +
         sum(here * 2 + 2, mid + 1, end, left, right);
}

int main(void)
{
  fastio;

  cin >> n;
  tree.resize(1 << ((int)ceil(log2(n)) + 1), 0);

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    ability.push_back(input);
    sortAbility.push_back(input);
  }

  sort(sortAbility.begin(), sortAbility.end());

  for (int i = 0; i < n; i++)
  {
    int rank = lower_bound(sortAbility.begin(), sortAbility.end(), ability[i]) - sortAbility.begin();
    update(0, 0, n - 1, rank, 1);
    cout << i - sum(0, 0, n - 1, 0, rank - 1) + 1 << endl;
  }

  return 0;
}