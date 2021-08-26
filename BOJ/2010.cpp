#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n;
  cin >> n;
  int ans = 1;

  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    ans += (input - 1);
  }

  cout << ans;

  return 0;
}