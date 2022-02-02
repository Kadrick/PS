/**
 * @file 1269.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief ans
 * @version 0.1
 * @date 2022-02-01 05:01
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

int a, b, input, ans;
set<int> aset, bset;

int main(void)
{
  fastio;

  cin >> a >> b;

  for (int i = 0; i < a; i++)
  {
    cin >> input;
    aset.insert(input);
  }

  for (int i = 0; i < b; i++)
  {
    cin >> input;
    bset.insert(input);
  }

  for (auto &&num : aset)
  {
    if (bset.find(num) == bset.end())
      ans++;
  }

  for (auto &&num : bset)
  {
    if (aset.find(num) == aset.end())
      ans++;
  }

  cout << ans << endl;

  return 0;
}