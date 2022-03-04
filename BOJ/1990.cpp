/**
 * @file 1990.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-03-04 02:38
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

bool isPrime(int num)
{
  if (num < 2)
    return false;

  for (int i = 2; i <= sqrt(num); i++)
    if (num % i == 0)
      return false;

  return true;
}

bool isPalindrome(string str)
{
  for (int i = 0; i < str.size() / 2; i++)
  {
    if (str[i] != str[str.size() - 1 - i])
      return false;
  }
  return true;
}

int main(void)
{
  fastio;

  int a, b;
  cin >> a >> b;

  for (int i = a; i <= 10000000; i++)
  {
    if (b < i)
      break;
    if (isPalindrome(to_string(i)) && isPrime(i))
      cout << i << endl;
  }
  cout << -1 << endl;

  return 0;
}