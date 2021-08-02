#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int n;
  cin >> n;
  for (int i = 0; i < 9; ++i) {
    int tmp;
    cin >> tmp;
    n -= tmp;
  }
  cout << n << endl;
  return 0;
}