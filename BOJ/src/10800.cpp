/**
 * @file 10800.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief prefix sum
 * @version 0.1
 * @date 2022-01-25 02:11
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

vector<int> ans;
vector<int> color;
vector<tuple<int, int, int>> arr;

int main(void)
{
  fastio;
  int n;
  cin >> n;

  ans.resize(n, 0);
  color.resize(n, 0);

  for (int i = 0; i < n; ++i)
  {
    int color, size;
    cin >> color >> size;
    arr.push_back(make_tuple(size, color - 1, i));
  }

  sort(arr.begin(), arr.end());

  int smaller = 0, total = 0;
  for (int i = 0; i < n; ++i)
  {
    for (; get<0>(arr[i]) > get<0>(arr[smaller]); smaller++)
    {
      total += get<0>(arr[smaller]);
      color[get<1>(arr[smaller])] += get<0>(arr[smaller]);
    }
    ans[get<2>(arr[i])] = total - color[get<1>(arr[i])];
  }

  for (int i = 0; i < n; ++i)
    cout << ans[i] << endl;

  return 0;
}