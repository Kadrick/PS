#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

class Point {
public:
  int y;
  int x;
  Point(int y, int x) : x(x), y(y) {}
};

int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<char>> board(101, vector<char>(101));
vector<vector<char>> rgboard(101, vector<char>(101));
vector<vector<bool>> isVisited;

bool inRange(int y, int x) { return 1 <= y && y <= n && 1 <= x && x <= n; }

void dfs(int y, int x, char &flag) {
  isVisited[y][x] = true;

  for (int i = 0; i < 4; ++i) {
    int movey = y + dy[i];
    int movex = x + dx[i];
    if (inRange(movey, movex) && board[movey][movex] == flag &&
        !isVisited[movey][movex]) {
      dfs(movey, movex, flag);
    }
  }
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'G')
        rgboard[i][j] = 'R';
      else
        rgboard[i][j] = board[i][j];
    }
  }
  isVisited.resize(101, vector<bool>(101, false));

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!isVisited[i][j]) {
        ans++;
        dfs(i, j, board[i][j]);
      }
    }
  }

  cout << ans << ' ';

  ans = 0;
  isVisited.clear();
  isVisited.resize(101, vector<bool>(101, false));
  board = rgboard;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (!isVisited[i][j]) {
        ans++;
        dfs(i, j, board[i][j]);
      }
    }
  }

  cout << ans;

  return 0;
}