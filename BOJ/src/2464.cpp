/**
 * @file 2464.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-05-26 10:32
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

long long binary_str_to_ll(string str)
{
  long long ret = 0;

  long long base = 1;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] - '0' == 1)
      ret += base;
    base *= 2;
  }

  return ret;
}

int main(void)
{
  fastio;

  long long n, origin;
  cin >> n;
  origin = n;
  string pivot_binary_str;

  while (n)
  {
    if (n & 1)
      pivot_binary_str.push_back('1');
    else
      pivot_binary_str.push_back('0');

    n >>= 1;
  }
  pivot_binary_str.push_back('0');

  int cnt = 0;
  string small, big;
  small = big = pivot_binary_str;

  // small
  for (int i = 0; i < small.size() - 1; i++)
  {
    if (small[i] == '1')
      cnt++;

    if (small[i] == '0' && small[i + 1] == '1')
    {
      swap(small[i], small[i + 1]);

      for (int j = i - 1; j >= 0; j--)
        small[j] = cnt-- > 0 ? '1' : '0';
      break;
    }
  }

  // big
  cnt = 0;
  for (int i = 0; i < big.size() - 1; i++)
  {
    if (big[i] == '0')
      cnt++;

    if (big[i] == '1' && big[i + 1] == '0')
    {
      swap(big[i], big[i + 1]);

      for (int j = i - 1; j >= 0; j--)
        big[j] = cnt-- > 0 ? '0' : '1';
      break;
    }
  }

  long long big_int = binary_str_to_ll(big);
  long long small_int = binary_str_to_ll(small);

  if (small_int == origin)
    small_int = 0;

  cout << small_int << ' ' << big_int << endl;

  return 0;
}