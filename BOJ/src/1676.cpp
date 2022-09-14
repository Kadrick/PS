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

  int cnttwo = 0, cntfive = 0;

  for (int i = 1; i <= n; ++i) {
    int target = i;
    for (int j = 2; j <= target; ++j) {
      while (target % j == 0) {
        target /= j;
        if (j == 2)
          cnttwo++;
        if (j == 5)
          cntfive++;
      }
    }
  }

  cout << min(cnttwo, cntfive);

  return 0;
}