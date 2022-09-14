#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int t, v, e;
  cin >> t;
  while (t--) {
    cin >> v >> e;
    cout << 2 - v + e << endl;
  }

  return 0;
}