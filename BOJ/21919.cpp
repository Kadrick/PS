#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int floor = 1000001;
  vector<bool> isPrime(floor, true);
  vector<bool> isMulti(floor, false);

  isPrime[1] = false;
  for (int i = 2; i < floor / 2; ++i) {
    if (!isPrime[i])
      continue;
    for (int j = 2; j * i < floor; j++)
      isPrime[i * j] = false;
  }

  int n;
  cin >> n;
  long long ans = 1;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (isPrime[tmp])
      isMulti[tmp] = true;
  }

  for (int i = 2; i < floor; i++) {
    if (isMulti[i])
      ans *= i;
  }

  if (ans == 1)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}