#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int floor = 1e6 + 1;
  vector<bool> isPrime(floor, true);

  isPrime[1] = false;
  for (int i = 2; i <= floor / 2; ++i) {
    if (!isPrime[i])
      continue;
    for (int j = 2; j * i < floor; j++)
      isPrime[i * j] = false;
  }
  while (true) {
    int k = 2;
    long long n;
    cin >> n;
    if (n == 0)
      break;
    if (n == 1) {
      cout << 1 << endl;
      return 0;
    }

    vector<long long> save;
    long long ans = n;

    while (n) {
      if (n == 1)
        break;
      if (k >= floor) {
        save.push_back(n);
        break;
      }
      if (isPrime[k]) {
        if (n % k == 0)
          save.push_back(k);
        while (n % k == 0)
          n /= k;
        k++;
      } else {
        k++;
      }
    }

    for (auto p : save) {
      ans = (ans / p) * (p - 1);
    }

    cout << ans << endl;
  }

  return 0;
}