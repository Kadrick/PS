#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int ans = 0;
  for (int i = 0; i < 5; ++i) {
    int tmp;
    cin >> tmp;
    ans += tmp * tmp;
  }

  cout << ans % 10;

  return 0;
}