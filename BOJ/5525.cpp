#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, ans;
string input;
int cache[1000001];

int main(void) {
  fastio;

  cin >> n >> m;
  cin >> input;

  for (int i = 2; i < m; ++i) {
    if (input[i] == 'I') {
      if (input[i - 2] == 'I' && input[i - 1] == 'O') {
        cache[i] = cache[i - 2] + 1;
        if (cache[i] >= n)
          ans++;
        continue;
      }
    }
  }

  cout << ans;

  return 0;
}