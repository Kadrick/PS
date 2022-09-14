/**
 * @file 7561.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-01-27 04:41
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

#define int int64_t

int det(vector<vector<int>> &matrix)
{
  int t1 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
  int t2 = matrix[1][0] * (matrix[2][1] * matrix[0][2] - matrix[0][1] * matrix[2][2]);
  int t3 = matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
  return t1 + t2 + t3;
}

int32_t main(void)
{
  fastio;
  int tc;
  cin >> tc;
  while (tc--)
  {
    vector<vector<int>> full(3, vector<int>(4, 0));
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 4; j++)
        cin >> full[i][j];
    }

    vector<vector<int>> A(3, vector<int>(3, 0));
    vector<vector<int>> A_i(3, vector<int>(3, 0));

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
        A[i][j] = full[i][j];
    }

    int denominator = det(A);
    int numerator[3];
    for (int i = 0; i < 3; i++)
    {
      A_i = A;
      for (int j = 0; j < 3; j++)
        A_i[j][i] = full[j][3];
      numerator[i] = det(A_i);
    }

    cout << numerator[0] << ' ' << numerator[1] << ' '
         << numerator[2] << ' ' << denominator << endl;

    if (denominator == 0)
      cout << "No unique solution" << endl;
    else
    {
      cout << fixed;
      cout.precision(3);
      cout << "Unique solution: ";
      for (int i = 0; i < 3; i++)
      {
        double ret = (double)numerator[i] / denominator;
        if (-0.0005 < ret && ret < 0.0005)
          cout << "0.000" << ' ';
        else
          cout << ret << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}