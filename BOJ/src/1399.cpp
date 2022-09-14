/**
 * @file 1399.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-02-10 02:40
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

int dig(int n)
{
  if (n <= 9)
    return n;

  int ret = 0;

  while (n)
  {
    ret += n % 10;
    n /= 10;
  }

  return dig(ret);
}

int32_t main(void)
{
  fastio;

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int tc;
  cin >> tc;
  while (tc--)
  {
    int k, m, g = 1;
    cin >> k >> m;

    int start = 0;
    pair<int, int> here = {0, 0};
    vector<pair<int, int>> cycle;
    bool find = false;
    for (int step = 0; step < k; step++)
    {
      here.first += dx[step % 4] * g;
      here.second += dy[step % 4] * g;

      for (int cnt = 0; cnt < cycle.size(); cnt++)
      {
        if (cycle[cnt] == here)
        {
          find = true;
          start = cnt;
          break;
        }
      }

      if (find)
        break;

      cycle.push_back(here);

      g *= m;
      g = dig(g);
    }

    if (find)
    {
      k -= start + 1;
      int remainder = k % (cycle.size() - start);
      here.first = cycle[start + remainder].first;
      here.second = cycle[start + remainder].second;
    }

    cout << here.first << ' ' << here.second << endl;
  }

  return 0;
}