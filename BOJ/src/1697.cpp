#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, k, ans = 2e9;
vector<bool> isVisited(100001, false);
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (cur.first == k) {
      ans = min(ans, cur.second);
      continue;
    }

    if (cur.second >= ans)
      continue;

    if (cur.first > k) {
      q.push(make_pair(k, cur.second + cur.first - k));
      continue;
    }

    if (cur.first <= 50000 && !isVisited[cur.first * 2]) {
      isVisited[cur.first * 2] = true;
      q.push(make_pair(cur.first * 2, cur.second + 1));
    }

    if (cur.first < 100000 && !isVisited[cur.first + 1]) {
      isVisited[cur.first + 1] = true;
      q.push(make_pair(cur.first + 1, cur.second + 1));
    }

    if (cur.first > 0 && !isVisited[cur.first - 1]) {
      isVisited[cur.first - 1] = true;
      q.push(make_pair(cur.first - 1, cur.second + 1));
    }
  }
}

int main(void) {
  fastio;

  cin >> n >> k;
  q.push(make_pair(n, 0));
  isVisited[n] = true;

  bfs();

  cout << ans;

  return 0;
}