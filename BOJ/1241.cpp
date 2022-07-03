/**
 * @file 1241.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-07-03 18:50
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

  vector<int> human(n, 0), ans(n, 0);
  for (int i = 0; i < n; i++)
    cin >> human[i];

  vector<int> cnt(1000001, 0);
  for (int i = 0; i < n; i++)
    cnt[human[i]]++;

  for (int i = 0; i < n; i++)
  {
    int base = 1;
    while (base * base <= human[i])
    {
      if (human[i] % base == 0)
      {
        ans[i] += cnt[base];
        if (base * base != human[i])
          ans[i] += cnt[human[i] / base];
      }
      base++;
    }
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] - 1 << endl;

  return 0;
}