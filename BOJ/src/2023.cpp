#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<int> prime;

bool isPrime(int number) {

  for (int i = 2; i <= sqrt(number); ++i) {
    if (number % i == 0)
      return false;
  }

  return true;
}

void trace(string &ans) {
  if (ans.length() == n) {
    cout << ans << endl;
    return;
  }

  for (int i = 0; i < 10; ++i) {
    ans.push_back(i + '0');
    if (isPrime(atoi(ans.c_str())))
      trace(ans);
    ans.pop_back();
  }
}

int main(void) {
  fastio;

  cin >> n;
  prime.push_back(2);
  prime.push_back(3);
  prime.push_back(5);
  prime.push_back(7);

  string ans;
  for (int i = 0; i < 4; ++i) {
    ans.push_back(prime[i] + '0');
    trace(ans);
    ans.pop_back();
  }

  return 0;
}