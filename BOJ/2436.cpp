/**
 * @file 2436.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-05-16 09:11
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

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main(void)
{
  fastio;

  long long a, b;
  cin >> a >> b;

  // lcd * gcd = a * b
  long long total = a * b;
  long long pivot = sqrt(total);

  pair<long long, long long> ans = {LLONG_MAX, 0};
  while (true)
  {
    if (total % pivot == 0)
    {
      if (pivot + total / pivot < ans.first && gcd(pivot, total / pivot) == a)
      {
        ans.first = pivot + total / pivot;
        ans.second = pivot;
      }
      if (pivot == a)
        break;
    }
    pivot--;
  }

  cout << ans.second << ' ' << total / ans.second << endl;

  return 0;
}