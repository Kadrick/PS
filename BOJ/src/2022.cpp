/**
 * @file 2022.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math + binary search
 * @version 0.1
 * @date 2022-02-09 12:51
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

double x, y, c;

int main(void)
{
  fastio;

  cin >> x >> y >> c;
  cout << fixed;
  cout.precision(3);

  double bottom = 0.0, top = min(x, y);
  double ans = 0.0;

  x = pow(x, 2);
  y = pow(y, 2);

  while (abs(top - bottom) > 1e-6)
  {
    double mid = (top + bottom) / 2.0;
    double sq_mid = pow(mid, 2);

    double left_h = sqrt(x - sq_mid);
    double right_h = sqrt(y - sq_mid);
    double h = (left_h * right_h) / (left_h + right_h);

    if (h >= c)
    {
      ans = mid;
      bottom = mid;
    }
    else
      top = mid;
  }

  cout << ans << endl;

  return 0;
}