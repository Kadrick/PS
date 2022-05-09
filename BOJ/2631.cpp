/**
 * @file 2631.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief LIS
 * @version 0.1
 * @date 2022-05-09 10:33
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

  int n, ans = 0;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> lis(n, 0);

  for (int i = 0; i < n; i++)
  {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;

      ans = max(ans, lis[i]);
    }
  }

  cout << n - ans << endl;

  return 0;
}