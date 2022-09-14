/**
 * @file 19621.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BackTracking
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, ans;
vector<int> arr;

int solve(int idx)
{
  if (idx > n)
    return 0;

  int ret = arr[idx];

  for (int i = idx + 2; i < n; i++)
    ret = max(ret, arr[idx] + solve(i));

  return ret;
}

int main(void)
{
  fastio;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int s, e, p;
    cin >> s >> e >> p;
    arr.push_back(p);
  }

  cout << max(solve(0), solve(1)) << endl;

  return 0;
}