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
  string tmp;
  cin >> tmp;

  long long ans = 0;
  long long r = 1;
  long long mod = 1234567891;
  for (int i = 0; i < n; ++i) {
    ans += ((tmp[i] - 'a' + 1) * r) % mod;
    r = (r * 31) % mod;
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}