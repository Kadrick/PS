/**
 * @file 1358.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-07-01 17:02
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

#define x first
#define y second

bool IsPointInCircle(
    const pair<int, pair<int, int>> &circle,
    const pair<int, int> &point)
{

  int dx = point.x - circle.second.x;
  int dy = point.y - circle.second.y;

  int dist = dx * dx + dy * dy;

  if (dist <= circle.first * circle.first)
    return true;
  return false;
}

bool IsPointInRect(
    const pair<pair<int, int>, pair<int, int>> &rect,
    const pair<int, int> &point)
{
  if (rect.first.x <= point.x && point.x <= rect.second.x)
  {
    if (rect.first.y <= point.y && point.y <= rect.second.y)
      return true;
    return false;
  }

  return false;
}

int main(void)
{
  fastio;

  int width, height, x, y, n;
  cin >> width >> height >> x >> y >> n;

  pair<int, pair<int, int>> lcircle = {height / 2, {x, y + height / 2}};
  pair<int, pair<int, int>> rcircle = {height / 2, {x + width, y + height / 2}};
  pair<pair<int, int>, pair<int, int>> rect = {{x, y}, {x + width, y + height}};

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    pair<int, int> player;
    cin >> player.x >> player.y;

    if (IsPointInCircle(lcircle, player) || IsPointInCircle(rcircle, player) || IsPointInRect(rect, player))
      ans++;
  }
  cout << ans << endl;
  return 0;
}