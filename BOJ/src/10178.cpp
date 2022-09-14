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
  while (t--) {
    int u, v;
    cin >> u >> v;

    cout << "You get " << u / v << " piece(s) and your dad gets " << u % v
         << " piece(s)." << endl;
  }

  return 0;
}