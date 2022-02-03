/**
 * @file 20041.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-02-03
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

#define int long long

int n;
bool block[4]; // clockwise (up - right - down - left)
pair<int, int> person;
vector<pair<int, int>> police;

int32_t main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int xpos, ypos;
    cin >> xpos >> ypos;
    police.push_back({xpos, ypos});
  }
  cin >> person.first >> person.second;

  for (auto &&p : police)
  {
    int x_diff = p.first - person.first;
    int y_diff = p.second - person.second;

    if (x_diff >= 0 && y_diff >= 0)
    {
      if (x_diff >= y_diff)
        block[1] = true; // right
      if (x_diff <= y_diff)
        block[0] = true; // up
    }
    if (x_diff <= 0 && y_diff >= 0)
    {
      if (abs(x_diff) >= y_diff)
        block[3] = true; // left
      if (abs(x_diff) <= y_diff)
        block[0] = true; // up
    }
    if (x_diff <= 0 && y_diff <= 0)
    {
      if (abs(x_diff) >= abs(y_diff))
        block[3] = true; // left
      if (abs(x_diff) <= abs(y_diff))
        block[2] = true; // down
    }
    if (x_diff >= 0 && y_diff <= 0)
    {
      if (x_diff >= abs(y_diff))
        block[1] = true; // right
      if (x_diff <= abs(y_diff))
        block[2] = true; // down
    }
  }

  int cnt_block = 0;
  for (auto &&dir : block)
  {
    if (dir)
      cnt_block++;
  }

  cout << (cnt_block != 4 ? "YES" : "NO") << endl;

  return 0;
}