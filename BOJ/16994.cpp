/**
 * @file 16994.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief rope
 * @version 0.1
 * @date 2022-01-31 03:44
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int main(void)
{
  fastio;

  rope<char> rp;
  string input;
  cin >> input;
  rp.append(input.c_str());

  int query;
  cin >> query;

  while (query--)
  {
    int order, x, y;
    cin >> order;

    if (order == 1)
    {
      cin >> x >> y;
      rp = rp.substr(x, y - x + 1) + rp.substr(0, x) + rp.substr(y + 1, input.size());
    }
    else if (order == 2)
    {
      cin >> x >> y;
      rp = rp.substr(0, x) + rp.substr(y + 1, input.size()) + rp.substr(x, y - x + 1);
    }
    else
    {
      cin >> x;
      cout << rp.at(x) << endl;
    }
  }

  return 0;
}