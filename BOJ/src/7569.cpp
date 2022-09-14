#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};

int m, n, h, ans;
int tomatoBox[101][101][101];
bool isVisited[101][101][101];

class Point {
public:
  Point(int z, int y, int x) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  int x;
  int y;
  int z;
};

queue<pair<Point, int>> q;
bool inRange(int z, int y, int x) {
  return (1 <= z && z <= h && 1 <= y && y <= n && 1 <= x && x <= m);
}

void bfs() {
  while (!q.empty()) {
    pair<Point, int> front = q.front();
    q.pop();

    ans = max(ans, front.second);

    for (int i = 0; i < 6; ++i) {
      int movez = front.first.z + dh[i];
      int movey = front.first.y + dy[i];
      int movex = front.first.x + dx[i];

      if (inRange(movez, movey, movex) && tomatoBox[movez][movey][movex] == 0 &&
          !isVisited[movez][movey][movex]) {
        tomatoBox[movez][movey][movex] = 1;
        isVisited[movez][movey][movex] = true;
        q.push(make_pair(Point(movez, movey, movex), front.second + 1));
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> m >> n >> h;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= m; ++k) {
        cin >> tomatoBox[i][j][k];
      }
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= m; ++k) {
        if (tomatoBox[i][j][k] == 1) {
          q.push(make_pair(Point(i, j, k), 0));
          isVisited[i][j][k] = true;
        }
      }
    }
  }

  bfs();

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= m; ++k) {
        if (tomatoBox[i][j][k] == 0) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  cout << ans;

  return 0;
}