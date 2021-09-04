#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef struct _Point {
  int y;
  int x;
  _Point(int y, int x) {
    this->y = y;
    this->x = x;
  }
} Point;

int w, h;
bool board[1001][1001];
bool isVisited[2][1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inRange(int y, int x) { return 1 <= y && y <= h && 1 <= x && x <= w; }

int bfs() {
  int ret = -1;
  queue<tuple<Point, int, bool>> q;
  q.push(make_tuple(Point(1, 1), 1, false));

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    Point pos = get<0>(cur);
    int dist = get<1>(cur);
    bool drill = get<2>(cur);

    if (pos.y == h && pos.x == w) {
      ret = dist;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int move_y = pos.y + dy[i];
      int move_x = pos.x + dx[i];

      if (inRange(move_y, move_x) && !board[move_y][move_x] &&
          !isVisited[drill][move_y][move_x]) {
        q.push(make_tuple(Point(move_y, move_x), dist + 1, drill));
        isVisited[drill][move_y][move_x] = true;
      } else if (inRange(move_y, move_x) && board[move_y][move_x] && !drill &&
                 !isVisited[drill][move_y][move_x]) {
        isVisited[drill][move_y][move_x] = true;
        q.push(make_tuple(Point(move_y, move_x), dist + 1, !drill));
      }
    }
  }

  return ret;
}

int main(void) {
  fastio;

  char input;
  cin >> h >> w;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> input;
      board[i + 1][j + 1] = input - '0';
    }
  }

  cout << bfs();

  return 0;
}