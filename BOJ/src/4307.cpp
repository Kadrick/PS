/**
 * @file 4307.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-02-14 02:30
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

  int tc;
  cin >> tc;
  while (tc--)
  {
    int stick, n;
    cin >> stick >> n;

    int minret = 0, maxret = 0;
    for (int i = 0; i < n; i++)
    {
      int pos;
      cin >> pos;

      int bottom = min(pos, stick - pos);
      int top = max(pos, stick - pos);

      minret = max(minret, bottom);
      maxret = max(maxret, top);
    }
    cout << minret << ' ' << maxret << endl;
  }

  return 0;
}