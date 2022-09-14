#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;

    string str;
    for (int j = n; j <= m; ++j) {
      str += to_string(j);
    }

    int cnt = 0;
    for (char &ch : str) {
      if (ch == '0')
        cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}