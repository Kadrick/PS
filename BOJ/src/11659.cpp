#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<int> sum;

int main(void) {
  fastio;

  cin >> n >> m;
  sum.resize(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    sum[i + 1] = sum[i] + num;
  }

  for (int i = 0; i < m; ++i) {
    int s, e;
    cin >> s >> e;
    cout << sum[e] - sum[s - 1] << endl;
  }

  return 0;
}