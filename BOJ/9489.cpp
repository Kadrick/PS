/**
 * @file 9489.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief tree
 * @version 0.1
 * @date 2022-03-23 01:54
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

void solve(int n, int k)
{
  int find_idx = 0, set_cnt = -1;
  vector<int> array(n + 1, -1), parent(n + 1, -1);

  for (int i = 1; i <= n; i++)
  {
    cin >> array[i];
    if (array[i] == k)
      find_idx = i;
    if (array[i] != array[i - 1] + 1)
      set_cnt += 1;
    parent[i] = set_cnt;
  }

  int ret = 0;

  for (int i = 1; i <= n; i++)
  {
    if (parent[i] != parent[find_idx] &&
        parent[parent[i]] == parent[parent[find_idx]])
      ret += 1;
  }

  cout << ret << endl;
}

int main(void)
{
  fastio;

  int n, k;
  while (true)
  {
    cin >> n >> k;
    if (n == k && n == 0)
      break;
    solve(n, k);
  }

  return 0;
}