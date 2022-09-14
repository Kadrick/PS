#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, x, k;
  cin >> n >> x >> k;

  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == x) {
      x = b;
    } else if (b == x) {
      x = a;
    }
  }

  cout << x;

  return 0;
}