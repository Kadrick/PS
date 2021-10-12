/***********************************
> File Name: 7869.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/13 01:06
> Description: geometry
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

double getDist(double x, double y, double a, double b)
{
  return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

int main(void)
{
  fastio;

  cout << fixed;
  cout.precision(3);

  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  double dist = getDist(x1, y1, x2, y2);

  if (r1 < r2)
  {
    swap(x1, x2);
    swap(y1, y2);
    swap(r1, r2);
  }

  if (dist >= r1 + r2)
    cout << (double)0;
  else if (r1 >= dist + r2)
    cout << pow(r2, 2) * M_PI;
  else
  {
    double thetaSmall = 2 * acos((pow(r2, 2) + pow(dist, 2) - pow(r1, 2)) / (2 * r2 * dist));
    double thetaBig = 2 * acos((pow(r1, 2) + pow(dist, 2) - pow(r2, 2)) / (2 * r1 * dist));

    double arrowSmall = thetaSmall * pow(r2, 2) - sin(thetaSmall) * pow(r2, 2);
    double arrowBig = thetaBig * pow(r1, 2) - sin(thetaBig) * pow(r1, 2);

    cout << (arrowSmall + arrowBig) / 2;
  }

  return 0;
}