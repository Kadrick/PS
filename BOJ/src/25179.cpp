/**
 * @file 25179.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief game theory
 * @version 0.1
 * @date 2022-05-17 09:09
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

  long long n, unit;
  cin >> n >> unit;
  n -= 1;
  unit += 1;
  if (n % unit)
    cout << "Can win" << endl;
  else
    cout << "Can't win" << endl;

  return 0;
}