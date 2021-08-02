#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int limit = 1e6 + 1;
vector<bool> isPrime(limit, true);

long long Euler(long long n) {
  int k = 2;

  if (n == 1) {
    return 1;
  }

  vector<long long> save;
  long long ans = n;

  while (n) {
    if (n == 1)
      break;
    if (k >= limit) {
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
  return ans;
}

int main(void) {
  fastio;

  isPrime[1] = false;
  for (int i = 2; i <= limit / 2; ++i) {
    if (!isPrime[i])
      continue;
    for (int j = 2; j * i < limit; j++)
      isPrime[i * j] = false;
  }
  int bign;
  cin >> bign;
  vector<int> div;
  div.push_back(1);
  div.push_back(2);
  for (int i = 3; i <= sqrt(bign); ++i) {
    if (bign % i == 0) {
      div.push_back(i);
      div.push_back(bign / i);
    }
  }
  long long greatans = 2e9;

  for (long long n : div) {
    if (Euler(n) * n == (long long)bign) {
      greatans = min(n, greatans);
    }
  }

  if (greatans == 2e9)
    cout << -1;
  else
    cout << greatans;

  return 0;
}