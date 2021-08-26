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

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j)
      cout << "*";
    for (int j = 1; j <= 2 * n - 2 * i; ++j)
      cout << " ";
    for (int j = 1; j <= i; ++j)
      cout << "*";
    cout << endl;
  }
  for (int i = n - 1; i >= 1; --i) {
    for (int j = 1; j <= i; ++j)
      cout << "*";
    for (int j = 1; j <= 2 * n - 2 * i; ++j)
      cout << " ";
    for (int j = 1; j <= i; ++j)
      cout << "*";
    cout << endl;
  }

  return 0;
}