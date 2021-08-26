#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    int input;
    cin >> input;
    sum += input;
  }

  cout << sum;

  return 0;
}