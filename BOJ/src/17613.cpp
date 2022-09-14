/***********************************
> File Name: 17613.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/14 19:50
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long l, r;
map<pair<long, long>, int> dp;

int solve(long long left, long long right)
{
  if (left == 0 && right == 0)
    return 0;
  if (dp.find({left, right}) != dp.end())
    return dp[{left, right}];

  int ret = 0;

  for (int i = 1; i < 41; i++)
  {
    long long start = ((long long)1 << i) - 1;
    long long end = ((long long)1 << (i + 1)) - 2;

    start = max(start, left);
    end = min(end, right);

    if (start <= end)
    {
      ret = max(
          ret,
          solve(
              start + 1 - ((long long)1 << i),
              end + 1 - ((long long)1 << i)) +
              i);
    }
  }

  return dp[{left, right}] = ret;
}

int main(void)
{
  fastio;

  int tc;
  cin >> tc;
  while (tc--)
  {
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }

  return 0;
}