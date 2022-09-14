/***********************************
> File Name: 9996.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/17 02:!1
> Description: string
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
string input, standard, add = "[a-z]";
vector<string> judges;

int main(void)
{
  fastio;

  cin >> n >> standard;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    judges.push_back(input);
  }

  int pos = 0;
  while (true)
  {
    pos = standard.find('*', pos);
    if (pos == string::npos)
      break;

    standard.insert(pos, add);
    pos += 7;
  }

  regex target(standard);
  for (int i = 0; i < n; i++)
  {
    bool isPass = regex_match(judges[i], target);

    if (isPass)
      cout << "DA" << endl;
    else
      cout << "NE" << endl;
  }

  return 0;
}