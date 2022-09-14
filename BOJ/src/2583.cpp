#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef struct Point {
  int y;
  int x;
  Point(int y, int x) : x(x), y(y) {}
} Point;

int m, n, k, cnt;
int board[101][101];
vector<int> ans;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool inRange(int y, int x) { return 1 <= y && y <= n && 1 <= x && x <= m; }

int bfs(int y, int x) {
  int res = 0;
  queue<Point> q;
  q.push(Point(y, x));
  board[y][x] = 1;
  res++;

  while (!q.empty()) {
    Point cur = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int movex = cur.x + dx[i];
      int movey = cur.y + dy[i];

      if (inRange(movey, movex) && board[movey][movex] == 0) {
        board[movey][movex] = 1;
        q.push(Point(movey, movex));
        res++;
      }
    }
  }

  return res;
}

int main(void) {
  fastio;

  cin >> n >> m >> k;

  for (int i = 0; i < k; ++i) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    for (int j = sy + 1; j <= ey; ++j) {
      for (int k = sx + 1; k <= ex; ++k) {
        board[j][k] = 1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (board[i][j] == 0) {
        cnt++;
        ans.push_back(bfs(i, j));
      }
    }
  }

  cout << cnt << endl;
  sort(ans.begin(), ans.end());
  for (auto i : ans)
    cout << i << ' ';

  return 0;
}