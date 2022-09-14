/**
 * @file 1202.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-03-23 01:36
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

#define weight first
#define cost second

int n, k, idx;
long long ret;
pair<int, int> jew[300001];
int bag[300001];
priority_queue<int> pq;

bool comp(pair<int, int> &left, pair<int, int> &right)
{
  if (left.weight == right.weight)
    return left.cost > right.cost;
  return left.weight < right.weight;
}

int main(void)
{
  fastio;

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> jew[i].weight >> jew[i].cost;
  for (int i = 0; i < k; i++)
    cin >> bag[i];

  sort(jew, jew + n, comp);
  sort(bag, bag + k);

  for (int i = 0; i < k; i++)
  {
    while (idx < n && jew[idx].weight <= bag[i])
      pq.push(jew[idx++].cost);

    if (pq.size())
    {
      ret += pq.top();
      pq.pop();
    }
  }

  cout << ret << endl;

  return 0;
}