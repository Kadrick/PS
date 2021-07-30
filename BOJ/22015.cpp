#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int a, b, c;
  cin >> a >> b >> c;

  int pivot = max(a, max(b, c));
  cout << pivot * 3 - (a + b + c);

  return 0;
}