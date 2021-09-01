#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int board_size, ans;
int board[101][101];
bool isVisited[101][101];
vector<int> height;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inRange(int y, int x) {
  return 1 <= y && y <= board_size && 1 <= x && x <= board_size;
}

void dfs(int y, int x, int height) {
  isVisited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (!inRange(ny, nx))
      continue;
    if (board[ny][nx] > height && !isVisited[ny][nx])
      dfs(ny, nx, height);
  }
}

int main(void) {
  fastio;

  cin >> board_size;
  for (int i = 1; i <= board_size; ++i) {
    for (int j = 1; j <= board_size; ++j) {
      cin >> board[i][j];
      height.push_back(board[i][j]);
    }
  }

  height.push_back(0);
  sort(height.begin(), height.end());
  height.erase(unique(height.begin(), height.end()), height.end());

  for (auto &&h : height) {
    int safe = 0;
    memset(isVisited, false, sizeof(isVisited));

    for (int j = 1; j <= board_size; ++j) {
      for (int k = 1; k <= board_size; ++k) {
        if (board[j][k] > h && !isVisited[j][k]) {
          safe++;
          dfs(j, k, h);
        }
      }
    }

    ans = max(ans, safe);
  }

  cout << ans;

  return 0;
}