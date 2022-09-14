/**
 * @file 2470.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief two pointers
 * @version 0.1
 * @date 2022-04-11 20:53
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

void solve(int n, vector<int> &water)
{
  pair<int, int> ans;
  int left = 0, right = n - 1;
  ans.first = ans.second = 1e9;
  while (left < right)
  {
    if (abs(water[left] + water[right]) <= abs(ans.first + ans.second))
    {
      ans.first = water[left];
      ans.second = water[right];

      if (ans.first + ans.second == 0)
        break;
    }

    if (water[left] + water[right] < 0)
      left++;
    else
      right--;
  }

  cout << ans.first << ' ' << ans.second << endl;
}

int main(void)
{
  fastio;

  int n;
  vector<int> water;
  cin >> n;
  water.resize(n);
  for (int i = 0; i < n; i++)
    cin >> water[i];

  sort(water.begin(), water.end());
  solve(n, water);

  return 0;
}