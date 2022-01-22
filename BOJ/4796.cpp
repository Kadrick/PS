/**
 * @file 4796.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-01-23 05:51
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

int main(void) {
  fastio;

  long long round = 0;
  while (true) {
    long long l, p, v, ans = 0;
    cin >> l >> p >> v;
    if(l == p && p == v && l == 0) break;
    
    ans += v / p * l;
    ans += (v % p) > l ? l : v % p;   

    cout << "Case " << ++round << ": " << ans << endl;
  }

  return 0;
}