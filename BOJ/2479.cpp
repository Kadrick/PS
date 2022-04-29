/**
 * @file 2479.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief map
 * @version 0.1
 * @date 2022-04-29 10:38
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

  int n, k, start, end;
  cin >> n >> k;

  vector<int> parent(n + 1, -1);
  vector<string> bucket(n + 1, "");

  unordered_map<string, int> table;

  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;
    table[input] = i + 1;
    bucket[i + 1] = input;
  }

  cin >> start >> end;

  queue<pair<string, int>> q;
  q.push({bucket[start], start});

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();

    if (front.first == bucket[end])
      break;

    for (int i = 0; i < k; i++)
    {
      string trans = front.first;
      trans[i] = (trans[i] == '0' ? '1' : '0');

      auto pos = table.find(trans);
      if (pos == table.end() || parent[(*pos).second] != -1 || (*pos).second == start)
        continue;

      parent[(*pos).second] = front.second;
      q.push({trans, (*pos).second});
    }
  }
  
  if (parent[end] == -1)
    cout << -1 << endl;
  else
  {
    vector<int> ans;
    ans.push_back(end);
    end = parent[end];

    while (end != -1)
    {
      ans.push_back(end);
      end = parent[end];
    }

    for (int i = ans.size() - 1; i >= 0; i--)
      cout << ans[i] << ' ';
    cout << endl;
  }

  return 0;
}