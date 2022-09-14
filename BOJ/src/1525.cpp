/**
 * @file 1525.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-03-12 03:36
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

int main(void)
{
  fastio;

  auto inRange = [&](int &x, int &y)
  {
    return 0 <= x && x < 3 && 0 <= y && y < 3;
  };

  queue<pair<string, int>> q;
  set<string> visited;
  bool find = false;
  char ch;
  string input;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};

  for (int i = 0; i < 9; i++)
  {
    cin >> ch;
    input.push_back(ch);
  }

  q.push({input, 0});
  visited.insert(input);
  while (q.size())
  {
    string here = q.front().first;
    int dist = q.front().second;
    q.pop();

    if (here == "123456780")
    {
      find = true;
      cout << dist << endl;
      break;
    }

    int x = here.find('0') % 3;
    int y = here.find('0') / 3;

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!inRange(nx, ny))
        continue;

      string next = here;
      swap(next[y * 3 + x], next[ny * 3 + nx]);
      if (visited.find(next) != visited.end())
        continue;

      q.push({next, dist + 1});
      visited.insert(next);
    }
  }

  if (!find)
    cout << -1 << endl;

  return 0;
}