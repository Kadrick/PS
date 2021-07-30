#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }

int main(void) {
  fastio;

  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
    int n, m;
    cin >> n >> m;

    int p = 0, q = 0;
    vector<pair<int, int>> point;

    for (int i = 0; i < m; i++) {
      int idx, val;
      cin >> idx >> val;
      point.push_back(make_pair(idx, val));
    }

    int pset[3] = {0, 100, 100};

    int idx = 2;

    for (auto &&dot : point) {
      if (dot.first < 3) {
        pset[dot.first] = dot.second;
      } else {
        q += (dot.first - idx) * dot.second;
        idx = dot.first;
      }
    }

    if (pset[1] != 100 && pset[2] == 100) {
      p = pset[1] * 2;
    } else {
      p = pset[1] + pset[2];
    }

    q += p;

    int gcd = GCD(p, q);
    cout << p / gcd << '/' << q / gcd << endl;
  }

  return 0;
}