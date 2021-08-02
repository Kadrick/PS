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
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      cout << ' ';
    }
    for (int j = 0; j < (n - i) * 2 - 1; ++j) {
      cout << '*';
    }
    cout << endl;
  }
  return 0;
}