/**
 * @file 10840.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief stl set + sliding window
 * @version 0.1
 * @date 2022-03-07 04:16
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

string str1, str2;
set<vector<int>> s;

int main(void)
{
  fastio;

  cin >> str1 >> str2;
  if (str2.length() < str1.length())
    swap(str1, str2);

  for (int i = 1; i <= str1.size(); i++)
  {
    vector<int> cnt(26, 0);
    int start = 0, end = i - 1;

    for (int j = 0; j <= end; j++)
      cnt[str1[j] - 'a']++;

    while (end < str1.size())
    {
      s.insert(cnt);
      if (end + 1 < str1.size())
      {
        cnt[str1[start] - 'a'] -= 1;
        cnt[str1[end + 1] - 'a'] += 1;
      }
      start++;
      end++;
    }
  }

  for (int i = str2.size(); i >= 1; i--)
  {
    vector<int> cnt(26, 0);
    int start = 0, end = i - 1;

    for (int j = 0; j <= end; j++)
      cnt[str2[j] - 'a']++;

    while (end < str2.size())
    {
      if (s.find(cnt) != s.end())
      {
        cout << i << endl;
        return 0;
      }
      if (end + 1 < str2.size())
      {
        cnt[str2[start] - 'a'] -= 1;
        cnt[str2[end + 1] - 'a'] += 1;
      }
      start++;
      end++;
    }
  }

  cout << 0 << endl;

  return 0;
}