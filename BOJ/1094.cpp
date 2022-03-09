/**
 * @file 1094.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-03-10 01:22
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

int main(void)
{
  fastio;

  int n;
  cin >> n;

  int cnt = 0;

  while (n)
  {
    if (n & 1)
      cnt++;
    n >>= 1;
  }

  cout << cnt << endl;

  return 0;
}