#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, ans = 2e9;
vector<vector<bool>> board;
vector<vector<int>> step;

bool inRange(int y, int x) {
  return (0 <= y) && (y < n) && (0 <= x) && (x < m);
}

void bfs(int starty, int startx) {
  queue<pair<int, int>> q;
  q.push(make_pair(starty, startx));

  step[starty][startx] = 1;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (cur.first == n - 1 && cur.second == m - 1) {
      ans = step[n - 1][m - 1];
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int movey = cur.first + dy[i];
      int movex = cur.second + dx[i];

      if (inRange(movey, movex) && board[movey][movex] && !step[movey][movex]) {
        step[movey][movex] = step[cur.first][cur.second] + 1;
        q.push(make_pair(movey, movex));
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> m;
  board.resize(n, vector<bool>(m));
  step.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; ++j) {
      if (tmp[j] == '1')
        board[i][j] = true;
      else
        board[i][j] = false;
    }
  }

  bfs(0, 0);

  cout << ans << endl;

  return 0;
}