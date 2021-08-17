#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
bool g[26][26];

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string input, is, output;
    cin >> input >> is >> output;
    g[input[0] - 'a'][output[0] - 'a'] = true;
  }

  for (int k = 0; k < 26; ++k) {
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (g[i][j])
          continue;

        if (g[i][k] && g[k][j])
          g[i][j] = true;
      }
    }
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    string input, is, output;
    cin >> input >> is >> output;
    if (g[input[0] - 'a'][output[0] - 'a'])
      cout << "T" << endl;
    else
      cout << "F" << endl;
  }

  return 0;
}