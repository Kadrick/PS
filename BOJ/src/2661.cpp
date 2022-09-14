/***********************************
> File Name: 2661.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/11 17:22
> Description: backtracking
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
string number;

void solve(int before)
{
  int sz = number.size();

  // i is length that compare strings
  for (int i = 2; i <= sz / 2; i++)
  {
    string a = number.substr(sz - i * 2, i);
    string b = number.substr(sz - i, i);

    //bad
    if (a == b)
      return;
  }

  if (number.size() == n)
  {
    cout << number;
    exit(0);
  }

  // good
  for (int i = 0; i < 3; i++)
  {
    if (i + 1 == before)
      continue;
    number.push_back(i + 1 + '0');
    solve(i + 1);
    number.pop_back();
  }
}

int main(void)
{
  fastio;

  cin >> n;

  for (int i = 0; i < 3; i++)
  {
    number.push_back(i + 1 + '0');
    solve(i + 1);
    number.pop_back();
  }

  return 0;
}