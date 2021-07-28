#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int ans;
bool board[101][101];

int main(void) {
  fastio;

  for (int i = 0; i < 4; ++i) {
    int left_bottom_x;
    int left_bottom_y;
    int right_up_x;
    int right_up_y;

    cin >> left_bottom_x >> left_bottom_y >> right_up_x >> right_up_y;

    for (int i = left_bottom_y; i < right_up_y; ++i) {
      for (int j = left_bottom_x; j < right_up_x; ++j) {
        if (!board[i][j]) {
          board[i][j] = true;
          ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}