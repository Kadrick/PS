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

  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = 0; j < n - abs(n - i - 1); ++j) {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}