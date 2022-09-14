/***********************************
> File Name: 15726.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/10 01:38 KST
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

  double a, b, c;
  cin >> a >> b >> c;
  cout << (int)floor(max((a * b) / c, (a / b) * c));

  return 0;
}