#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

class Point {
public:
  Point(int y, int x) {
    this->x = x;
    this->y = y;
  }
  int x;
  int y;
};

int m, n, ans;
int tomatoBox[1001][1001];
bool isVisited[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool inRange(int y, int x) { return (1 <= y && y <= n && 1 <= x && x <= m); }
queue<pair<Point, int>> q;

void bfs() {
  while (!q.empty()) {
    pair<Point, int> cur = q.front();
    q.pop();

    ans = max(ans, cur.second);

    for (int i = 0; i < 4; ++i) {
      int movey = cur.first.y + dy[i];
      int movex = cur.first.x + dx[i];

      if (inRange(movey, movex) && tomatoBox[movey][movex] == 0 &&
          !isVisited[movey][movex]) {
        tomatoBox[movey][movex] = 1;
        isVisited[movey][movex] = true;
        q.push(make_pair(Point(movey, movex), cur.second + 1));
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> tomatoBox[i + 1][j + 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tomatoBox[i + 1][j + 1] == 1) {
        q.push(make_pair(Point(i + 1, j + 1), 0));
      }
    }
  }

  bfs();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tomatoBox[i + 1][j + 1] == 0) {
        cout << -1;
        return 0;
      }
    }
  }

  cout << ans;

  return 0;
}