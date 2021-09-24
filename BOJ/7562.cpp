/***********************************
> File Name: 7562.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/25 02:30
> Description: BFS
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

#define y first
#define x second
#define pii pair<int, int>

int l;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
pii src, dest;
vector<vector<bool>> board;

bool inRange(pii point) {
  return 0 <= point.y && point.y < l && 0 <= point.x && point.x < l;
}

int bfs() {
  int ret;
  queue<pair<pii, int>> q;
  q.push({src, 0});

  while (!q.empty()) {
    auto here = q.front();
    q.pop();

    if (here.first == dest) {
      ret = here.second;
      break;
    }

    for (int i = 0; i < 8; ++i) {
      int movex = here.first.x + dx[i];
      int movey = here.first.y + dy[i];

      if (!inRange({movey, movex}))
        continue;
      if (board[movey][movex])
        continue;

      board[movey][movex] = true;
      q.push({{movey, movex}, here.second + 1});
    }
  }

  return ret;
}

int main(void) {
  fastio;

  int tc;
  cin >> tc;
  while (tc--) {
    board.clear();
    cin >> l;
    board.resize(l, vector<bool>(l, false));
    cin >> src.y >> src.x;
    cin >> dest.y >> dest.x;
    cout << bfs() << endl;
  }

  return 0;
}