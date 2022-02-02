/**
 * @file 1947.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-02-03
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
vector<long long> dp;

int main(void)
{
  fastio;

  cin >> n;
  dp.resize(1000001, 0);
  dp[2] = 1;
  dp[3] = 2;

  for (int i = 4; i <= n; i++)
    dp[i] = ((dp[i - 1] + dp[i - 2]) * (i - 1)) % (long long)1e9;

  cout << dp[n] << endl;

  return 0;
}