/**
 * @file 1448.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sort
 * @version 0.1
 * @date 2022-03-14 00:59
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

int n;
vector<int> num;

int main(void)
{
  fastio;

  cin >> n;
  num.resize(n);
  for (int i = 0; i < n; i++)
    cin >> num[i];

  sort(num.begin(), num.end(), greater<int>());

  for (int i = 0; i < num.size() - 2; i++)
  {
    if (num[i + 1] + num[i + 2] > num[i])
    {
      cout << num[i] + num[i + 1] + num[i + 2] << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}