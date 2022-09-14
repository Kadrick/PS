#include <bits/stdc++.h>
#define fastio                                                                 \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define endl '\n'
using namespace std;

int n;
int g[101][101];

int main(void) {
  fastio;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (g[j][k] == 1)
          continue;

        if (g[j][i] == 1 && g[i][k])
          g[j][k] = 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << g[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}