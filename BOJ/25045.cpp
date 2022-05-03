/**
 * @file 25045.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sort
 * @version 0.1
 * @date 2022-05-03 13:38
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

int n, m, ans;
vector<int> product, company;

int32_t main(void)
{
  fastio;

  cin >> n >> m;

  product.resize(n);
  company.resize(m);

  for (int i = 0; i < n; i++)
    cin >> product[i];

  for (int i = 0; i < m; i++)
    cin >> company[i];

  sort(product.begin(), product.end(), greater<int>());
  sort(company.begin(), company.end());

  for (int i = 0; i < min(n, m); i++)
    ans += max(0ll, product[i] - company[i]);

  cout << ans << endl;

  return 0;
}