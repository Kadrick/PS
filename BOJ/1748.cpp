/***********************************
> File Name: 1748.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/20 02:21
> Description: math
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int main(void)
{
  fastio;

  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i *= 10)
    ans += (n - i + 1);
  cout << ans;

  return 0;
}