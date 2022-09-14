#include <bits/stdc++.h>
#include <cmath>
#include <ios>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  long double a, b;
  cin >> a >> b;
  cout << fixed;
  cout.precision(9);
  cout << (a + b) / (1 + a * b / (pow(299'792'458ULL, 2ULL)));

  return 0;
}