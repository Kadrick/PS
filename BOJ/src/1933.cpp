/**
 * @file 1933.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sweep line
 * @version 0.1
 * @date 2022-03-05 17:50
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl ' '

int n;

vector<pair<int, pair<int, int>>> building;

bool comp(pair<int, pair<int, int>> &left, pair<int, pair<int, int>> &right)
{
  if (left.first == right.first)
  {
    if (left.second.second == right.second.second)
      return left.second.second == 0 ? left.second.first > right.second.first : left.second.first < right.second.first;
    return left.second.second < right.second.second;
  }
  return left.first < right.first;
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int l, h, r;
    cin >> l >> h >> r;
    building.push_back({l, {h, 0}});
    building.push_back({r, {h, 1}});
  }

  sort(building.begin(), building.end(), comp);

  multiset<int> skyline;

  for (auto &here : building)
  {
    if (!here.second.second)
    {
      // up position
      if (skyline.empty() || *skyline.rbegin() < here.second.first)
        cout << here.first << ' ' << here.second.first << endl;
      skyline.insert(here.second.first);
    }
    else
    {
      // down position
      int top = *skyline.rbegin();
      auto ret = skyline.find(here.second.first);
      if (ret != skyline.end())
        skyline.erase(ret);

      if (skyline.empty())
        cout << here.first << ' ' << 0 << endl;
      else if (top != *skyline.rbegin())
        cout << here.first << ' ' << *skyline.rbegin() << endl;
    }
  }

  return 0;
}