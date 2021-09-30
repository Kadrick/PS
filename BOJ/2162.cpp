/***********************************
> File Name: 2162.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/28 20:40
> Description: ccw / disjoint set
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
#define point pair<int, int>
#define line pair<point, point>

int n, ans, maxV = 1;
vector<line> lines;
int parent[3001];
int cnt[3001];

int ccw(point p1, point p2, point p3)
{
  int a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
  int b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
  int ret = a - b;
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


int find(int x)
{
  if (x == parent[x])
    return x;
  return find(parent[x]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u != v)
    parent[v] = u;
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
    line input;
    cin >> input.src.x >> input.src.y >> input.dest.x >> input.dest.y;
    lines.push_back(input);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (cross(lines[i], lines[j]))
        merge(i, j);
    }
  }

  for (int i = 0; i < n; i++)
    cnt[find(i)]++;

  for (int i = 0; i < n; i++)
  {
    if (cnt[i])
      ans++;
    maxV = max(maxV, cnt[i]);
  }

  cout << ans << endl;
  cout << maxV << endl;

  return 0;
}