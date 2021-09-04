#include <bits/stdc++.h>
#include <queue>
#include <sys/ucontext.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, input;
  cin >> n;

  priority_queue<int, vector<int>, greater<>> pq;

  for (int i = 0; i < n * n; ++i) {
    cin >> input;
    if (pq.size() < n)
      pq.push(input);
    else {
      if (pq.top() < input) {
        pq.pop();
        pq.push(input);
      }
    }
  }

  cout << pq.top();

  return 0;
}