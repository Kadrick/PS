/**
 * @file 17623.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-05-27 10:46
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

string dp[1001];
unordered_map<char, int> mapping;

string comp(string left, string right)
{
  if (left.length() == right.length())
  {
    for (int i = 0; i < left.length(); i++)
    {
      if (mapping[left[i]] < mapping[right[i]])
        return left;
      else if (mapping[left[i]] > mapping[right[i]])
        return right;
    }
  }
  return left.length() < right.length() ? left : right;
}

int main(void)
{
  fastio;

  mapping.insert({'(', 1});
  mapping.insert({')', 2});
  mapping.insert({'{', 3});
  mapping.insert({'}', 4});
  mapping.insert({'[', 5});
  mapping.insert({']', 6});

  dp[1] = "()";
  dp[2] = "{}";
  dp[3] = "[]";

  for (int i = 4; i < 1001; i++)
  {
    dp[i] = dp[i - 1] + dp[1];
    for (int j = 1; j <= i; j++)
    {
      dp[i] = comp(dp[i], dp[i - j] + dp[j]);
      dp[i] = comp(dp[i], dp[j] + dp[i - j]);
    }

    if (i % 2 == 0)
      dp[i] = comp(dp[i], "(" + dp[i / 2] + ")");
    if (i % 3 == 0)
      dp[i] = comp(dp[i], "{" + dp[i / 3] + "}");
    if (i % 5 == 0)
      dp[i] = comp(dp[i], "[" + dp[i / 5] + "]");
  }

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }

  return 0;
}