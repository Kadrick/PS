/***********************************
> File Name: 17216.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 21:32
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int length, ans;
vector<int> arr;
vector<int> dp;

int solve()
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[j] > arr[i] && dp[i] < dp[j] + arr[i])
        dp[i] = arr[i] + dp[j];
    }
    ans = max(dp[i], ans);
  }

  return ans;
}

int main()
{
  fastio;

  cin >> length;
  arr.resize(length);
  dp.resize(length);

  for (int i = 0; i < length; i++)
  {
    cin >> arr[i];
    dp[i] = arr[i];
  }

  cout << solve() << endl;

  return 0;
}