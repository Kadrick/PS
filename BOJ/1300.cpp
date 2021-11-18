/***********************************
> File Name: 1300.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/18 02:15
> Description: Binary Search
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long n, k;
long long l, r, ans;

int main(void)
{
  fastio;

  cin >> n >> k;
  l = 1;
  r = k;
  while (l <= r)
  {
    // amount of it less than k
    long long kmin = 0;
    long long mid = (l + r) >> 1;
    for (int i = 0; i < n; i++)
      kmin += min(mid / (i + 1), n);

    // binary search
    if (kmin < k)
      l = mid + 1;
    else
    {
      ans = mid;
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}