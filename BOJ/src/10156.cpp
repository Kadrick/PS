/**
 * @file 10156.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-01-31 13:09
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

  int cost, n, money;
  cin >> cost >> n >> money;

  cout << ((money - cost * n < 0) ? (cost * n - money) : 0) << endl;

  return 0;
}