#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    int credit = 0;
    vector<int> w(n);
    vector<double> g(n);
    for (int j = 0; j < n; ++j) {
      cin >> w[j] >> g[j];
      credit += w[j];
    }

    double ans = 0.0;
    for (int j = 0; j < n; ++j) {
      ans += (double)w[j] / (double)credit * g[j];
    }
    cout.precision(2);
    cout << credit << ' ' << ans << endl;
  }

  return 0;
}