/**
 * @file 3024.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief Brute Force
 * @version 0.1
 * @date 2022-01-30 03:06
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

  vector<string> board(n);
  for (int i = 0; i < n; i++)
    cin >> board[i];

  for (int i = 0; i < n - 3 + 1; i++)
  {
    for (int j = 0; j < n - 3 + 1; j++)
    {
      /* vertical check */
      for (int k = 0; k < 3; k++)
      {
        if (board[i][j + k] == board[i + 1][j + k] &&
            board[i + 1][j + k] == board[i + 2][j + k])
        {
          if (board[i][j + k] == '.')
            continue;
          cout << board[i][j + k] << endl;
          return 0;
        }
      }

      /* horizontal check */
      for (int k = 0; k < 3; k++)
      {
        if (board[i + k][j] == board[i + k][j + 1] &&
            board[i + k][j + 1] == board[i + k][j + 2])
        {
          if (board[i + k][j] == '.')
            continue;

          cout << board[i + k][j] << endl;
          return 0;
        }
      }

      /* diagonal check */
      if (board[i][j] == board[i + 1][j + 1] &&
          board[i + 1][j + 1] == board[i + 2][j + 2])
      {
        if (board[i][j] == '.')
          continue;

        cout << board[i][j] << endl;
        return 0;
      }
      if (board[i + 2][j] == board[i + 1][j + 1] &&
          board[i + 1][j + 1] == board[i][j + 2])
      {
        if (board[i + 1][j + 1] == '.')
          continue;

        cout << board[i + 1][j + 1] << endl;
        return 0;
      }
    }
  }
  cout << "ongoing" << endl;
  return 0;
}