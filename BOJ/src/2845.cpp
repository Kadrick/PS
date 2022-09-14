#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int l, p;
  cin >> l >> p;
  for (int i = 0; i < 5; ++i) {
    int input;
    cin >> input;
    cout << input - l * p << ' ';
  }

  return 0;
}