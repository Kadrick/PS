#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  long long a, b;
  cin >> a >> b;

  queue<pair<long long, long long>> q;
  q.push(make_pair(0, a));

  while (!q.empty()) {
    pair<long long, long long> front = q.front();
    q.pop();

    if (front.second == b) {
      cout << front.first + 1 << endl;
      return 0;
    }

    if (front.second * 2 <= b)
      q.push(make_pair(front.first + 1, front.second * 2));
    if (front.second * 10 + 1 <= b)
      q.push(make_pair(front.first + 1, front.second * 10 + 1));
  }

  cout << -1 << endl;

  return 0;
}