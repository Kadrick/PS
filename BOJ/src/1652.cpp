/***********************************
> File Name: 1652.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/01 02:45
> Description: implement
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

bool isFind;
int n, ansX, ansY;
char board[101][101];

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    isFind = false;
    for (int j = 0; j < n - 1; j++)
    {
      if (board[i][j] == 'X')
      {
        isFind = false;
        continue;
      }
      if (isFind)
        continue;
      if (board[i][j + 1] == '.')
      {
        ++ansX;
        isFind = true;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    isFind = false;
    for (int j = 0; j < n - 1; j++)
    {
      if (board[j][i] == 'X')
      {
        isFind = false;
        continue;
      }
      if (isFind)
        continue;
      if (board[j + 1][i] == '.')
      {
        ++ansY;
        isFind = true;
      }
    }
  }

  cout << ansX << ' ' << ansY;

  return 0;
}