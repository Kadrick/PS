//author : kadrick
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, ans = 0, input;
  cin >> n;
  for (int i = 0; i < 5; ++i) {
    cin >> input;
    if(n == input) ans++;
  }

  cout << ans;

  return 0;
}