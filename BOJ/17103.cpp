#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

bool isPrime[1000001];

int main(void) {
  fastio;

  memset(isPrime, true, sizeof(isPrime));

  for (int i = 2; i <= 500000; ++i) {
    if (!isPrime[i])
      continue;

    for (int j = 2; i * j <= 1000000; ++j) {
      isPrime[i * j] = false;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 0;
    cin >> n;

    for (int i = 2; i <= n / 2; ++i) {
      if (isPrime[i] && isPrime[n - i])
        cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}