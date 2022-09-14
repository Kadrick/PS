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

  string unit;
  cin >> unit;

  string ans;

  for (int i = 0; i < input.size(); ++i) {
    ans += input[i];

    if (ans.length() < unit.length())
      continue;
    if (ans.back() == unit.back()) {
      int cnt = 0;
      bool check = true;
      while (check && unit.length() > cnt) {
        if (ans[ans.length() - 1 - cnt] != unit[unit.length() - 1 - cnt]) {
          check = false;
          break;
        }
        cnt++;
      }
      if (check) {
        for (auto ch : unit)
          ans.pop_back();
      }
    }
  }

  if (ans.length() == 0)
    cout << "FRULA";
  else
    cout << ans;

  return 0;
}