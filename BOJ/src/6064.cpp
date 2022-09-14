#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(void) {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    int tx = x, ty = x, cnt = x;
    int upperBound = lcm(m, n);
    if (ty > n) {
      ty = ty % n;
      if (ty == 0)
        ty = n;
    }
    while (true) {
      if (ty == y)
        break;

      if (cnt > upperBound)
        break;

      ty += m;
      cnt += m;
      if (ty > n) {
        ty = ty % n;
        if (ty == 0)
          ty = n;
      }
    }

    if (cnt > upperBound)
      cout << -1 << endl;
    else
      cout << cnt << endl;
  }

  return 0;
}