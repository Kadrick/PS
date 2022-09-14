/**
 * @file 1684.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-02-10 02:17
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

int n, ans;
vector<int> arr;

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int main(void)
{
  fastio;

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  for (int i = 1; i < n; i++)
    arr[i - 1] = arr[i] - arr[i - 1];

  ans = arr[0];
  for (int i = 1; i < n - 1; i++)
    ans = gcd(ans, arr[i]);

  cout << ans << endl;

  return 0;
}