#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, b, hmax, hmin = 2e9;
vector<vector<int>> board;

int main(void) {
  fastio;

  cin >> n >> m >> b;
  board.resize(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      hmin = min(hmin, board[i][j]);
      hmax = max(hmax, board[i][j]);
    }
  }
  int tans = 2e9;
  int hans = 0;
  for (int h = hmin; h <= hmax; ++h) {
    int inven = b;
    int dig = 0;
    int add = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int pivot = board[i][j] - h;
        if (pivot > 0) {
          dig += pivot;

        } else if (pivot < 0) {
          add += -1 * pivot;
        }
      }
    }

    inven += dig;

    if (inven >= add) {
      int time = dig * 2 + add;
      if (time <= tans) {
        tans = time;
        hans = max(hans, h);
      }
    }
  }

  cout << tans << ' ' << hans << endl;

  return 0;
}