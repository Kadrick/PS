#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int w, h;
int board[51][51];

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};

bool inRange(int y, int x) { return 1 <= y && y <= h && 1 <= x && x <= w; }

int dfs(int y, int x) {
  int size = 1;
  board[y][x] = 0;

  for (int i = 0; i < 8; ++i) {
    int move_x = x + dx[i];
    int move_y = y + dy[i];

    if (inRange(move_y, move_x) && board[move_y][move_x]) {
      size += dfs(move_y, move_x);
    }
  }

  return size;
}

int main(void) {
  fastio;

  while (true) {
    int cnt = 0;
    cin >> w >> h;
    if (!w && !h)
      break;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> board[i + 1][j + 1];
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (board[i + 1][j + 1]) {
          int ret = dfs(i + 1, j + 1);
          if (ret >= 1)
            cnt++;
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}