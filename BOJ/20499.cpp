// author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  string input;
  cin >> input;

  int k = atoi(input.substr(0, input.find('/')).c_str());
  input = input.substr(input.find('/') + 1);
  int d = atoi(input.substr(0, input.find('/')).c_str());
  input = input.substr(input.find('/') + 1);
  int a = atoi(input.c_str());

  if (k + a < d || d == 0)
    cout << "hasu" << endl;
  else
    cout << "gosu" << endl;

  return 0;
}