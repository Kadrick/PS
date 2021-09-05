#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, k;
  cin >> n >> k;
  vector<bool> isVisited(100001, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, n});

  while (!pq.empty()) {
    auto cur = pq.top();
    int time = cur.first;
    int pos = cur.second;
    pq.pop();

    if (pos == k) {
      cout << cur.first;
      break;
    }

    if (pos * 2 <= 100000 && !isVisited[pos * 2]) {
      pq.push({time, pos * 2});
      isVisited[pos * 2] = true;
    }
    if (pos + 1 <= 100000 && !isVisited[pos + 1]) {
      pq.push({time + 1, pos + 1});
      isVisited[pos + 1] = true;
    }
    if (pos - 1 >= 0 && !isVisited[pos - 1]) {
      pq.push({time + 1, pos - 1});
      isVisited[pos - 1] = true;
    }
  }

  return 0;
}