/**
 * @file 14222.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief priority queue
 * @version 0.1
 * @date 2023-08-01 19:12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int main(void)
{
  fastio;

  int n, k;
  cin >> n >> k;

  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;
    pq.push(-num);
  }

  int target = 1;

  while (true)
  {
    if (target == n + 1)
    {
      cout << 1 << endl;
      break;
    }

    int smallest = -pq.top();

    if (smallest == target)
    {
      target++;
      pq.pop();
      continue;
    }

    if (smallest > target)
    {
      cout << 0 << endl;
      break;
    }

    if (smallest < target)
    {
      pq.pop();
      pq.push(-(smallest + k));
    }
  }

  return 0;
}