/***********************************
> File Name: 10799.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 19:05
> Description: stack
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

long long ans;
string input;
stack<char> st;

int main(void)
{
  fastio;

  cin >> input;

  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == '(')
    {
      st.push('(');
    }
    else if (input[i] == ')')
    {
      // steal or razor
      if (input[i - 1] == '(')
      {
        ans += st.size();
        ans--;
      }
      else
      {
        ans += 1;
      }
      st.pop();
    }
  }

  cout << ans;

  return 0;
}