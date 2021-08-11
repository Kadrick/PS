#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

long long n, m;

int main(void) {
  fastio;

  cin >> n >> m;
  cout << abs(n - m);

  return 0;
}