/***********************************
> File Name: 20149.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/29 17:16 
> Description: ccw
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define y first
#define x second
#define src first
#define dest second
#define point pair<long long, long long>
#define line pair<point, point>

vector<line> lines;

int ccw(point p1, point p2, point p3)
{
  long long a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
  long long b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
  long long ret = a - b;
  if (ret < 0)
    return -1;
  if (ret == 0)
    return 0;

  return 1;
}

bool cross(line a, line b)
{
  int atob = ccw(a.src, a.dest, b.src) * ccw(a.src, a.dest, b.dest);
  int btoa = ccw(b.src, b.dest, a.src) * ccw(b.src, b.dest, a.dest);

  if (atob == 0 && atob == btoa)
  {
    bool xpos = (min({a.src.x, a.dest.x}) <= min({b.src.x, b.dest.x}) &&
                 min({b.src.x, b.dest.x}) <= max({a.src.x, a.dest.x})) ||
                (min({b.src.x, b.dest.x}) <= min({a.src.x, a.dest.x}) &&
                 min({a.src.x, a.dest.x}) <= max({b.src.x, b.dest.x}));
    bool ypos = (min({a.src.y, a.dest.y}) <= min({b.src.y, b.dest.y}) &&
                 min({b.src.y, b.dest.y}) <= max({a.src.y, a.dest.y})) ||
                (min({b.src.y, b.dest.y}) <= min({a.src.y, a.dest.y}) &&
                 min({a.src.y, a.dest.y}) <= max({b.src.y, b.dest.y}));

    return xpos && ypos;
  }

  return atob <= 0 && btoa <= 0;
}

pair<double, double> findDot(line a, line b)
{
  pair<double, double> ret = {987654321.0, 987654321.0};
  double aSlope;
  if (a.src.x - a.dest.x != 0)
    aSlope = (double)(a.src.y - a.dest.y) / (a.src.x - a.dest.x);
  else
    aSlope = 987654321.0;

  double bSlope;
  if (b.src.x - b.dest.x != 0)
    bSlope = (double)(b.src.y - b.dest.y) / (b.src.x - b.dest.x);
  else
    bSlope = 987654321.0;

  if (bSlope == aSlope)
    return ret;

  if (aSlope == 987654321.0)
  {
    ret.x = a.src.x;
    ret.y = bSlope * (ret.x - b.src.x) + b.src.y;
  }
  else if (bSlope == 987654321.0)
  {
    ret.x = b.src.x;
    ret.y = aSlope * (ret.x - a.src.x) + a.src.y;
  }
  else
  {
    ret.x = (b.src.y - a.src.y + a.src.x * aSlope - b.src.x * bSlope) / (aSlope - bSlope);
    ret.y = aSlope * (ret.x - a.src.x) + a.src.y;
  }

  return ret;
}

int main(void)
{
  fastio;

  for (int i = 0; i < 2; i++)
  {
    line input;
    cin >> input.src.x >> input.src.y >> input.dest.x >> input.dest.y;
    lines.push_back(input);
  }

  if (cross(lines[0], lines[1]))
  {
    cout << 1 << endl;
    cout << fixed;
    cout.precision(12);
    if (lines[0].src >= lines[0].dest)
      swap(lines[0].src, lines[0].dest);
    if (lines[1].src >= lines[1].dest)
      swap(lines[1].src, lines[1].dest);

    if (lines[0].dest == lines[1].src)
    {
      cout << lines[0].dest.x << ' ' << lines[0].dest.y << endl;
      return 0;
    }
    else if (lines[1].dest == lines[0].src)
    {
      cout << lines[1].dest.x << ' ' << lines[1].dest.y << endl;
      return 0;
    }

    auto ret = findDot(lines[0], lines[1]);
    if (ret != pair<double, double>(987654321.0, 987654321.0))
    {
      cout << ret.x << ' ' << ret.y << endl;
    }
  }
  else
  {
    cout << 0 << endl;
  }

  return 0;
}