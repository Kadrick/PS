#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  string str;
  cin >> str;

  while (str.size() % 3) {
    str = "0" + str;
  }

  while (str.size()) {
    string unit = str.substr(0, 3);
    str = str.substr(3);

    cout << (unit[0] - '0') * 4 + (unit[1] - '0') * 2 + (unit[2] - '0') * 1;
  }

  return 0;
}