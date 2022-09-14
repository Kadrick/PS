/***********************************
> File Name: 11003.cpp
> Author: Kadrick
> Created Time: 2021/09/20 22:32
> Description: deque
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, l, input;
deque<pair<int, int>> dq;

int main(void) {
  fastio;

  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> input;
    // pop front data : out of range
    while (dq.size() && dq.front().second <= i - l) {
      dq.pop_front();
    }
    // pop back data : input is smallest
    while (dq.size() && dq.back().first >= input) {
      dq.pop_back();
    }
    dq.push_back({input, i});
    cout << dq.front().first << ' ';
  }

  return 0;
}