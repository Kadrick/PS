#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, k, s, y;
int student[2][3];

int main(void) {
  fastio;

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s >> y;
    y--;
    student[s][y / 2]++;
  }

  student[0][0] += student[1][0];
  student[1][0] = 0;
  int ans = 0, cnt = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 3; ++j) {
      cnt += student[i][j] / k;
      student[i][j] -= k * (student[i][j] / k);
      if (student[i][j])
        cnt++;

      ans += cnt;
      cnt = 0;
    }
  }

  cout << ans;

  return 0;
}