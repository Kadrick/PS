/**
 * @file 1484.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-01-31 14:16
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

  long long g;
  cin >> g;

  vector<long long> ans;
  long long before, after;
  before = after = 1;
  while (true)
  {
    if (before > after || after > 100000)
      break;

    long long pivot = after * after - before * before;

    if (pivot < g)
      after++;
    else if (pivot == g)
    {
      ans.push_back(after);
      after++;
    }
    else
      before++;
  }

  if (ans.size())
  {
    for (auto &&num : ans)
      cout << num << endl;
  }
  else
    cout << "-1" << endl;

  return 0;
}