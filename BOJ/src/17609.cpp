/**
 * @file 17609.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief recursion
 * @version 0.1
 * @date 2023-07-31 19:06
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int leftPalindrome(string &input, bool &shield, int start, int end)
{
  if (start >= end)
  {
    if (shield)
      return 0;
    else
      return 1;
  }

  if (input[start] == input[end])
    return leftPalindrome(input, shield, start + 1, end - 1);

  else if (!shield && input[start] != input[end])
    return 2;
  else if (shield && input[start + 1] == input[end])
  {
    shield = false;
    return leftPalindrome(input, shield, start + 2, end - 1);
  }
  else if (shield && start + 1 == end)
  {
    shield = false;
    return leftPalindrome(input, shield, start + 1, end);
  }

  return 2;
}

int rightPalindrome(string &input, bool &shield, int start, int end)
{
  if (start >= end)
  {
    if (shield)
      return 0;
    else
      return 1;
  }

  if (input[start] == input[end])
    return rightPalindrome(input, shield, start + 1, end - 1);

  else if (!shield && input[start] != input[end])
    return 2;
  else if (shield && input[start] == input[end - 1])
  {
    shield = false;
    return rightPalindrome(input, shield, start + 1, end - 2);
  }
  else if (shield && start + 1 == end)
  {
    shield = false;
    return rightPalindrome(input, shield, start + 1, end);
  }

  return 2;
}

int main(void)
{
  fastio;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    string input;
    cin >> input;

    bool shield = true;

    int ans = leftPalindrome(input, shield, 0, input.length() - 1);
    if (ans != 2)
      cout << ans << endl;
    else
    {
      shield = true;
      cout << rightPalindrome(input, shield, 0, input.length() - 1) << endl;
    }
  }

  return 0;
}