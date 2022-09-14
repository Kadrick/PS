/**
 * @file 9997.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief bitmask
 * @version 0.1
 * @date 2022-02-17 00:48
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
vector<int> words;

void solve(int idx, int visited)
{
  if (idx == n)
  {
    if (visited == (1 << 26) - 1)
      ans++;
    return;
  }

  solve(idx + 1, visited | words[idx]);
  solve(idx + 1, visited);
}

int main(void)
{
  fastio;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string input;
    cin >> input;

    int alpha = 0;
    for (int j = 0; j < input.size(); j++)
      alpha |= (1 << (input[j] - 'a'));
    words.push_back(alpha);
  }

  solve(0, 0);

  cout << ans << endl;

  return 0;
}