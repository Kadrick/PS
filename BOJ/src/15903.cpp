/**
 * @file 15903.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief priority queue
 * @version 0.1
 * @date 2022-01-20 01:35
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m, input;
long long ans;
priority_queue<long long> pq;

int main(void) {
  fastio;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> input;
    pq.push(-input);
  }
  
  while (m--) {
    auto c1 = -pq.top(); pq.pop();
    auto c2 = -pq.top(); pq.pop();
    pq.push(-(c1 + c2)); pq.push(-(c1 + c2));    
  }

  while (!pq.empty()) {
    ans -= pq.top();
    pq.pop();
  }
  cout << ans << endl;

  return 0;
}