/***********************************
> File Name: 1516.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/24 20:39
> Description: Topological sorting
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<int> graph[501];
int ans[501];
int times[501];
int inDegree[501];

void Topological() {
  queue<pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    if (inDegree[i] == 0) {
      ans[i] = times[i];
      q.push({i, times[i]});
    }
  }

  while (!q.empty()) {
    auto here = q.front();
    q.pop();

    for (auto &i : graph[here.first]) {
      inDegree[i]--;
      ans[i] = max(ans[i], here.second + times[i]);
      if (inDegree[i] == 0) {
        q.push({i, ans[i]});
      }
    }
  }
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> times[i + 1];
    while (true) {
      int input;
      cin >> input;
      if (input == -1)
        break;
      graph[input].push_back(i + 1);
      inDegree[i + 1]++;
    }
  }

  Topological();

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
}