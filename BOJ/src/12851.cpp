#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, k;
int ans_time = 987654321;
int ans_how;
bool isVisited[100001];

bool inRange(int pos) { return 0 <= pos && pos <= 100000; }

void bfs() {
  int step = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(n, 0));

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    isVisited[cur.first] = true;

    if (cur.first == k && ans_time == cur.second) {
      ans_how++;
    }

    if (cur.first == k && ans_time == 987654321) {
      ans_time = cur.second;
      ans_how++;
    }

    int movePos;
    movePos = cur.first + 1;
    if (inRange(movePos) && !isVisited[movePos]) {
      q.push(make_pair(movePos, cur.second + 1));
    }
    movePos = cur.first - 1;
    if (inRange(movePos) && !isVisited[movePos]) {
      q.push(make_pair(movePos, cur.second + 1));
    }
    movePos = cur.first * 2;
    if (inRange(movePos) && !isVisited[movePos]) {
      q.push(make_pair(movePos, cur.second + 1));
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> k;

  bfs();

  cout << ans_time << endl;
  cout << ans_how << endl;

  return 0;
}