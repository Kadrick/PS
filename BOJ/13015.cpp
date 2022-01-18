/**
 * @file 13015.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-01-19 07:26
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

int n;

int main(void)
{
  fastio;

  cin >> n;

  for (int i = 0; i < 2 * n - 1; i++)
  {
    if (i == 0 || i == 2 * n - 2)
    {
      for (int j = 0; j < n; j++)
        cout << '*';

      for (int j = 0; j < (n - 1) * 2 - 1; j++)
        cout << ' ';

      for (int j = 0; j < n; j++)
        cout << '*';
    }
    else if (i == n - 1)
    {
      for (int j = 0; j < n - 1; j++)
        cout << ' ';
      cout << '*';
      for (int j = 0; j < n - 2; j++)
        cout << ' ';
      cout << '*';
      for (int j = 0; j < n - 2; j++)
        cout << ' ';
      cout << '*';
    }
    else
    {
      for (int j = 0; j < (i >= n ? 2 * (n - 1) - i : i); j++)
        cout << ' ';
      cout << '*';
      for (int j = 0; j < n - 2; j++)
        cout << ' ';
      cout << '*';
      for (int j = 0; j < (i >= n ? (i - n + 1) * 2 - 1 : (n - 1) * 2 - 1 - i * 2); j++)
        cout << ' ';
      cout << '*';
      for (int j = 0; j < n - 2; j++)
        cout << ' ';
      cout << '*';
    }

    cout << endl;
  }

  return 0;
}