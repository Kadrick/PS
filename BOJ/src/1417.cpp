/**
 * @file 1417.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-01-24 20:51
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

  int n, dasom;
  cin >> n;

  priority_queue<int> ticket;
  cin >> dasom;
  for (int i = 0; i < n - 1; i++)
  {
    int input;
    cin >> input;
    ticket.push(input);
  }

  int ans = 0;
  while (!ticket.empty())
  {
    auto top = ticket.top();
    ticket.pop();

    if (top < dasom + ans)
      break;
    
    ans++;
    ticket.push(top - 1);      
  }
  
  cout << ans << endl;  
  
  return 0;
}