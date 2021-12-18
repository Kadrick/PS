/**
 * @file 11042.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief lucas theorem
 * @version 0.1
 * @date 2021-12-02 15:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long dp[2001][2001];

long long c(long long n, long long k, long long mod)
{
  long long &ret = dp[n][k];
  if (ret != -1)
    return ret;
  if (k == 0 || n == k)
    return ret = 1;
  return ret = (c(n - 1, k - 1, mod) + c(n - 1, k, mod)) % mod;
}

vector<long long> get_digits(long long number, long long base)
{
  vector<long long> ret;
  while (number)
  {
    ret.push_back(number % base);
    number /= base;
  }
  return ret;
}

long long lucas(long long n, long long k, long long prime)
{
  long long ret = 1;

  vector<long long> ndigits = get_digits(n, prime);
  vector<long long> kdigits = get_digits(k, prime);

  for (int i = 0; i < max(ndigits.size(), kdigits.size()); i++)
  {
    long long nvalue = i < ndigits.size() ? ndigits[i] : 0;
    long long kvalue = i < kdigits.size() ? kdigits[i] : 0;

    if (nvalue < kvalue)
      return 0;

    ret *= c(nvalue, kvalue, prime);
    ret %= prime;
  }

  return ret;
}

int main(void)
{
  fastio;

  memset(dp, -1, sizeof(dp));
  long long N, K, M;
  cin >> N >> K >> M;
  cout << lucas(N, K, M);
  return 0;
}