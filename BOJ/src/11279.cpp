#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
priority_queue<int> pq;

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int order;
    cin >> order;
    if (order == 0) {
      if (pq.empty()) {
        cout << 0 << endl;
      } else {

        cout << pq.top() << endl;
        pq.pop();
      }
    } else if (order > 0) {
      pq.push(order);
    }
  }

  return 0;
}