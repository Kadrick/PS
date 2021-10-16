/***********************************
> File Name: 13417.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/17 02:03
> Description: Greedy
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int main(void)
{
  fastio;

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    vector<char> input;
    string ans = "";

    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++)
      cin >> input[i];

    for (int i = 0; i < n; i++)
    {
      if (ans.empty())
      {
        ans.push_back(input[i]);
        continue;
      }

      if (ans.front() < input[i])
        ans.push_back(input[i]);
      else
        ans = input[i] + ans;
    }
    cout << ans << endl;
  }

  return 0;
}