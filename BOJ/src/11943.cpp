/***********************************
> File Name: 11943.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/10 01:33 KST
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

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(b + c, a + d);

  return 0;
}