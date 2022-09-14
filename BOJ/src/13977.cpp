/**
 * @file 13977.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-01-26 20:08
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

long long factorial[4000001];
long long MOD = 1e9 + 7;

// get x^p
long long lpow(long long x, long long p)
{
  if (p == 1)
    return x;

  if (p % 2)
    return (lpow(x, p - 1) * x) % MOD;
  long long half = lpow(x, p / 2) % MOD;
  return (half * half) % MOD;
}

int main(void)
{
  fastio;

  int m, n, k;
  cin >> m;
  factorial[0] = 1;
  for (int i = 1; i < 4000001; i++)
  {
    factorial[i] = factorial[i - 1] * i;
    factorial[i] %= MOD;
  }

  for (int i = 0; i < m; i++)
  {
    cin >> n >> k;
    long long a = factorial[n];
    long long b = factorial[k];
    b *= factorial[n - k];
    b %= MOD;
    long long convert = lpow(b, MOD - 2);

    cout << (a * convert) % MOD << endl;
  }

  return 0;
}