/**
 * @file 11191.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief linear algebra
 * @version 0.1
 * @date 2022-01-27 18:21
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

long long n, ans;
vector<long long> arr;
vector<long long> basis;

int main(void)
{
  fastio;

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  while (true)
  {
    long long mx = *(max_element(arr.begin(), arr.end()));
    if (mx == 0)
      break;
    basis.push_back(mx);
    for (int j = 0; j < n; j++)
    {
      if ((mx ^ arr[j]) < arr[j])
        arr[j] ^= mx;
    }
  }

  for (int i = 0; i < basis.size(); i++)
  {
    if (ans < (ans ^ basis[i]))
      ans ^= basis[i];
  }

  cout << ans << endl;

  return 0;
}