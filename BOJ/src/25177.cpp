/**
 * @file 25177.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-05-16 20:17
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

int n, m, ans;
vector<int> a, b;

int main(void)
{
  fastio;

  cin >> n >> m;
  a.resize(max(n, m), 0);
  b.resize(max(n, m), 0);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++)
    cin >> b[i];

  for (int i = 0; i < max(n, m); i++)
    ans = max(ans, b[i] - a[i]);

  cout << ans << endl;

  return 0;
}