/***********************************
> File Name: 17386.cpp
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

int main(void)
{
  fastio;

  for (int i = 0; i < 2; i++)
  {
    line input;
    cin >> input.src.x >> input.src.y >> input.dest.x >> input.dest.y;
    lines.push_back(input);
  }

  cout << cross(lines[0], lines[1]);

  return 0;
}