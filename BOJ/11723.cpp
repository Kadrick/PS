#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int m;
vector<bool> s(21, false);

int main(void) {
  fastio;

  cin >> m;

  for (int i = 0; i < m; ++i) {
    string order;
    cin >> order;

    int x;

    if (order == "add") {
      cin >> x;
      s[x] = true;
    } else if (order == "remove") {
      cin >> x;
      s[x] = false;
    } else if (order == "check") {
      cin >> x;
      if (s[x])
        cout << 1 << endl;
      else
        cout << 0 << endl;
    } else if (order == "toggle") {
      cin >> x;
      s[x] = !s[x];
    } else if (order == "all") {
      s.clear();
      s.resize(21, true);
    } else if (order == "empty") {
      s.clear();
      s.resize(21, false);
    }
  }

  return 0;
}