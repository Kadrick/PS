/**
 * @file 3107.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2023-08-02 18:49
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

vector<string> split(const string &input, char d)
{
  vector<string> result;

  string bucket = "";
  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == d)
    {
      result.push_back(bucket);
      bucket = "";
      continue;
    }
    bucket.push_back(input[i]);
  }
  result.push_back(bucket);

  return result;
}

int main(void)
{
  fastio;

  string input;
  cin >> input;

  vector<string> ip = split(input, ':');
  int need = 8 - int(ip.size());

  string ans = "";
  bool use = false;

  vector<string> newIP = vector<string>(0);

  for (int i = 0; i < ip.size(); i++)
  {
    if (ip[i] == "" && !use)
    {
      for (int j = 0; j < need; j++)
        newIP.push_back("");

      use = true;

      if (need == -1)
        continue;
    }
    newIP.push_back(ip[i]);
  }

  for (int i = 0; i < newIP.size(); i++)
  {
    string res = "0000";
    for (int j = 0; j < newIP[i].size(); j++)
      res.pop_back();

    ans += res + newIP[i];

    if (i != newIP.size() - 1)
      ans += ":";
  }

  cout << ans << endl;

  return 0;
}