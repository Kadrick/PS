#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int F, S, G, U, D;
vector<bool> isVisited;

int bfs(int start, int end) {
  int ret = -1;
  queue<pair<int, int>> q;
  q.push(make_pair(start, 0));
  isVisited[start] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (cur.first == end) {
      ret = cur.second;
      break;
    }

    if (U && cur.first + U <= F && !isVisited[cur.first + U]) {
      isVisited[cur.first + U] = true;
      q.push(make_pair(cur.first + U, cur.second + 1));
    }
    if (D && cur.first - D >= 1 && !isVisited[cur.first - D]) {
      isVisited[cur.first - D] = true;
      q.push(make_pair(cur.first - D, cur.second + 1));
    }
  }

  return ret;
}

int main(void) {
  fastio;

  cin >> F >> S >> G >> U >> D;
  isVisited.resize(F + 1, false);

  int ret = bfs(S, G);
  if (ret == -1)
    cout << "use the stairs" << endl;
  else
    cout << ret << endl;

  return 0;
}