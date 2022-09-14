/**
 * @file 19940.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Greedy
 * @version 0.1
 * @date 2022-04-29 10:12
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

void solve()
{
  int n;
  cin >> n;

  int addh, addt, addo;
  addh = addt = addo = 0;

  addh = n / 60;
  addt = (n % 60) / 10;
  addo = n % 10;

  if (addo > 5)
  {
    addt += 1;
    addo -= 10;
  }

  if (addt > 3)
  {
    addh += 1;
    addt -= 6;
  }

  if (addt < 0 && addo == 5)
  {
    addt += 1;
    addo -= 10;
  }

  cout << addh << ' ';
  cout << (addt > 0 ? addt : 0) << ' ';
  cout << (addt < 0 ? -addt : 0) << ' ';
  cout << (addo > 0 ? addo : 0) << ' ';
  cout << (addo < 0 ? -addo : 0) << endl;
}

int main(void)
{
  fastio;

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}