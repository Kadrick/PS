#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

bool isPrime[1000001];
vector<int> prime;

int main(void) {
  fastio;

  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i <= sqrt(1000001); ++i) {
    if (!isPrime[i])
      continue;
    prime.push_back(i);
    for (int j = 2; i * j <= 1000000; ++j) {
      isPrime[i * j] = false;
    }
  }

  while (true) {
    int n;
    cin >> n;

    if (n == 0)
      break;

    int ans = 0;
    for (int i = 1; i < prime.size(); ++i) {
      if (isPrime[n - prime[i]]) {
        ans = prime[i];
        break;
      }
      if (n - prime[i] < prime[i])
        break;
    }

    if (ans)
      cout << n << " = " << ans << " + " << n - ans << endl;
    else
      cout << "Goldbach's conjecture is wrong.";
  }

  return 0;
}