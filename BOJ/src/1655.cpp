#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  priority_queue<int> max_queue;
  priority_queue<int, vector<int>, greater<>> min_queue;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;

    if (max_queue.size() > min_queue.size())
      min_queue.push(input);
    else
      max_queue.push(input);

    if (!max_queue.empty() && !min_queue.empty()) {
      if (max_queue.top() > min_queue.top()) {
        int maxV = max_queue.top();
        int minV = min_queue.top();

        max_queue.pop();
        min_queue.pop();

        max_queue.push(minV);
        min_queue.push(maxV);
      }
    }

    cout << max_queue.top() << endl;
  }

  return 0;
}