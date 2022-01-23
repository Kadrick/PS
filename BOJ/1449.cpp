/**
 * @file 1449.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-01-23 06:03
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

  int n, l, ans = 0;
  cin >> n >> l;
  vector<int> arr(n, 0);
  vector<bool> fix(1001, false);

  for (int i = 0; i < n; i++)
    cin >> arr[i];
    
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; ++i)
  {
    if (fix[arr[i]] == false)
    {
      for (int j = arr[i]; j < arr[i] + l; ++j)
        fix[j] = true;
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}