/***********************************
> File Name: 14600.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/16 02:08
> Description: Divide & Conquer
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define y first
#define x second

int k, x, y, tile = 1;
int ans[1 << 7 + 1][1 << 7 + 1];

bool checkBox(const pair<int, int> &pivot, const int &sz)
{
  for (int i = pivot.y; i < pivot.y + sz; i++)
  {
    for (int j = pivot.x; j < pivot.x + sz; j++)
      // already fill tile or hole
      if (ans[i][j] != 0)
        return false;
  }
  return true;
}

void fillCenter(const pair<int, int> &pivot, const int &sz)
{
  // check left top
  if (checkBox(pivot, sz))
    ans[pivot.y + sz - 1][pivot.x + sz - 1] = tile;
  // check right top
  if (checkBox({pivot.y, pivot.x + sz}, sz))
    ans[pivot.y + sz - 1][pivot.x + sz] = tile;
  // check left down
  if (checkBox({pivot.y + sz, pivot.x}, sz))
    ans[pivot.y + sz][pivot.x + sz - 1] = tile;
  // check right down
  if (checkBox({pivot.y + sz, pivot.x + sz}, sz))
    ans[pivot.y + sz][pivot.x + sz] = tile;

  // next tile
  tile++;
}

void fill(pair<int, int> LT, int sz)
{
  fillCenter(LT, sz / 2);

  // if sz == 2, cant fill sz == 1 rect
  if (sz == 2)
    return;

  // left top
  fill(LT, sz / 2);
  // right top
  fill({LT.y, LT.x + sz / 2}, sz / 2);
  // left down
  fill({LT.y + sz / 2, LT.x}, sz / 2);
  // right down
  fill({LT.y + sz / 2, LT.x + sz / 2}, sz / 2);
}

int main(void)
{
  fastio;

  cin >> k >> x >> y;

  ans[y][x] = -1;

  fill({1, 1}, 1 << k);

  for (int i = (1 << k); i >= 1; i--)
  {
    for (int j = 1; j <= (1 << k); j++)
      cout << ans[i][j] << ' ';
    cout << endl;
  }

  return 0;
}