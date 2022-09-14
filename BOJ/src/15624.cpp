/***********************************
> File Name: 15624.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12
> Description: Divide & Conquer
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef vector<vector<ll>> matrix;

long long n = 2, MOD = 1000000007, p;
matrix base;

matrix operator*(const matrix &a, const matrix &b)
{
  matrix c;
  c.resize(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        c[i][j] += (a[i][k] * b[k][j]) % MOD;
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}

matrix pow(const matrix &A, long long m)
{
  if (m == 1)
    return A;
  if (m % 2 > 0)
    return pow(A, m - 1) * A;
  matrix half = pow(A, m / 2);
  return half * half;
}

void solve()
{
  base.resize(2, vector<long long>(2));
  base[0][0] = 1;
  base[0][1] = 1;
  base[1][0] = 1;
  base[1][1] = 0;

  cin >> p;
  if (p == 0)
    cout << 0 << endl;
  else if (p < 3)
    cout << 1 << endl;
  else
  {
    matrix ans = pow(base, p - 1);
    cout << (ans[1][0] + ans[1][1]) % MOD << endl;
  }
}

int main()
{
  fastio;

  solve();

  return 0;
}
