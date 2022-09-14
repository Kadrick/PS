/**
 * @file 8982.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief map
 * @version 0.1
 * @date 2022-05-04 09:04
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

#define Bottom pair<pair<int, int>, pair<int, int>>

int n, k, tmp, ans;
map<Bottom, int> sink;
vector<int> hole, up, down, width;

int main(void)
{
  fastio;

  cin >> n;
  cin >> tmp >> tmp;

  int size = (n - 2) / 2;
  up.resize(size, 0);
  down.resize(size, 0);
  width.resize(size, 0);

  for (int i = 0; i < size; i++)
  {
    pair<int, int> lpos, rpos;
    cin >> lpos.first >> lpos.second >> rpos.first >> rpos.second;
    sink[{lpos, rpos}] = i;
    down[i] = lpos.second;
    width[i] = rpos.first - lpos.first;
  }
  cin >> tmp >> tmp;

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    pair<int, int> lpos, rpos;
    cin >> lpos.first >> lpos.second >> rpos.first >> rpos.second;
    hole.push_back(sink[{lpos, rpos}]);
  }

  // update
  for (int i = 0; i < k; i++)
  {
    int ceiling = down[hole[i]];
    // left
    for (int j = hole[i] - 1; j >= 0; j--)
    {
      ceiling = min(ceiling, down[j]);
      up[j] = max(up[j], ceiling);
    }

    ceiling = down[hole[i]];
    // right
    for (int j = hole[i]; j < size; j++)
    {
      ceiling = min(ceiling, down[j]);
      up[j] = max(up[j], ceiling);
    }
  }

  for (int i = 0; i < size; i++)
  {
    if (up[i] < down[i])
      ans += (down[i] - up[i]) * width[i];
  }

  cout << ans << endl;

  return 0;
}