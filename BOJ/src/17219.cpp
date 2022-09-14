#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, m;
  cin >> n >> m;

  map<string, string> ssm;
  for (int i = 0; i < n; ++i) {
    string site, pass;
    cin >> site >> pass;
    ssm[site] = pass;
  }

  for (int i = 0; i < m; ++i) {
    string find;
    cin >> find;
    cout << ssm[find] << endl;
  }

  return 0;
}