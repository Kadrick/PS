#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int m, n;
  cin >> m >> n;

  vector<bool> isExpo(10001, false);
  for (int i = 1; i < 101; i++)
    isExpo[i * i] = true;

  int ansmin = 1e6;
  int anssum = 0;
  for (int i = m; i < n + 1; i++) {
    if (isExpo[i]) {
      ansmin = min(i, ansmin);
      anssum += i;
    }
  }

  if (anssum == 0)
    cout << -1 << endl;
  else {
    cout << anssum << endl;
    cout << ansmin << endl;
  }

  return 0;
}