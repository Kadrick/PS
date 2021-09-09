#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  long long a , b;
  cin >> a >> b;

  cout << (a+b)*(a-b);

  return 0;
}