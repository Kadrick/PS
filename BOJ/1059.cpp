#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int s, n, input;
  vector<int> S;
  cin >> s;

  for (int i = 0; i < s; ++i) {
    cin >> input;
    S.push_back(input);
  }

  cin >> n;

  sort(S.begin(), S.end());
  bool isCorrect = false;
  int start = 1, end = 1000;
  for (int i = 0; i < s; ++i) {

    if (n <= S[0]) {
      end = S[0] - 1;
      if (S[i] == n)
        isCorrect = true;
      break;
    }

    if (S[i] <= n && n <= S[i + 1]) {
      start = min(S[i] + 1, n);
      end = max(S[i + 1] - 1, n);
      if (S[i] == n || S[i + 1] == n)
        isCorrect = true;
      break;
    }
  }
  if (isCorrect) {
    cout << 0;
    return 0;
  }

  int cnt = 0;
  for (int i = start; i <= n; ++i) {
    for (int j = n; j <= end; ++j) {
      if (i != j) {
        cnt++;
      }
    }
  }

  cout << cnt;

  return 0;
}