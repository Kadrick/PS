/**
 * @file 1004.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-07-01 15:14
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

  if (dist < circle.first * circle.first)
    return true;
  return false;
}

int main(void)
{
  fastio;

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    pair<int, int> start, end;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;

    int n, ans = 0;
    cin >> n;
    vector<pair<int, pair<int, int>>> circles;
    for (int j = 0; j < n; j++)
    {
      pair<int, pair<int, int>> circle;
      cin >> circle.second.x >> circle.second.y >> circle.first;

      // exclusive or
      if (!IsPointInCircle(circle, start) != !IsPointInCircle(circle, end))
        ans++;
    }

    cout << ans << endl;
  }

  return 0;
}