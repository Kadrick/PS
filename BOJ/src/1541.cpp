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

  int ans = 0;
  bool check = false;
  string unit;
  for (auto &&i : input) {
    if (i == '-' || i == '+') {
      if (!check) {
        ans += atoi(unit.c_str());
      } else {
        ans -= atoi(unit.c_str());
      }
      if (i == '-')
        check = true;
      unit.clear();
    } else {
      unit.push_back(i);
    }
  }
  if (!check) {
    ans += atoi(unit.c_str());
  } else {
    ans -= atoi(unit.c_str());
  }
  cout << ans;
  return 0;
}