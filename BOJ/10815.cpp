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
  map<string, int> m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    m[to_string(tmp)] = tmp;
  }

  int findc;
  cin >> findc;
  for (int i = 0; i < findc; ++i) {
    int tmp;
    cin >> tmp;
    if (m.find(to_string(tmp)) == m.end()) {
      cout << 0 << ' ';
    } else {
      cout << 1 << ' ';
    }
  }

  return 0;
}