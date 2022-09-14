/**
 * @file 1689.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief sweep line
 * @version 0.1
 * @date 2022-01-29 02:27
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

  int n;
  cin >> n;

  vector<pair<long long, int>> lines;

  for (int i = 0; i < n; i++)
  {
    long long s, e;
    cin >> s >> e;

    lines.push_back({s, 1});
    lines.push_back({e, -1});
  }

  sort(lines.begin(), lines.end(),
       [](pair<long long, int> &left, pair<long long, int> &right)
       {
         if (left.first == right.first)
           return left.second < right.second;
         return left.first < right.first;
       });

  int ans = 0, cnt = 0;
  for (int i = 0; i < lines.size(); i++)
  {
    cnt += lines[i].second;
    ans = max(ans, cnt);
  }
  
  cout << ans << endl;

  return 0;
}