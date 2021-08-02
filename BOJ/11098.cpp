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
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    int maxC = 0;
    string ans;
    for (int j = 0; j < p; ++j) {
      int c;
      string name;
      cin >> c >> name;
      maxC = max(maxC, c);
      if (maxC == c)
        ans = name;
    }
    cout << ans << endl;
  }
  return 0;
}