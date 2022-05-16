/**
 * @file 25175.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-05-16 21:13
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

  int n, m, k;
  cin >> n >> m >> k;

  m -= 1; // zero based
  int jump = (k - 3) % n;

  cout << (m + jump + n) % n + 1 << endl;

  return 0;
}