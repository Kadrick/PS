/***********************************
> File Name: 5893.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/04 01:33
> Description: math
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int main()
{
  int respos;
  string input, shift, res, z = "";
  cin >> input;
  res = shift = input + "0000";
  respos = res.size();
  for (int i = input.size() - 1; i >= 0; i--)
  {
    respos--;
    if (input[i] == '0')
      continue;
    res[respos]++;
  }
  for (int i = res.size() - 1; i > 0; i--)
  {
    if (res[i] >= '2')
    {
      res[i - 1] += (res[i] - '0') / 2;
      res[i] = ((res[i] - '0') % 2) + '0';
    }
  }
  if (res[0] == '2')
    res[0] = '0', cout << "1";
  else if (res[0] == '3')
    res[0] = '1', cout << "1";
  else if (res[0] == '4')
    res[0] = '0', cout << "10";
  cout << res;
}