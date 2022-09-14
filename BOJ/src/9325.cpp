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
    long long car;
    cin >> car;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int cnt, price;
      cin >> cnt >> price;
      car += price * cnt;
    }
    cout << car << endl;
  }

  return 0;
}