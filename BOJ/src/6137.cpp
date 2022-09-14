/**
 * @file 6137.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-02-17 00:25
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

bool query(string& str, int left, int right) {
  if (left > right) return false;
  if (str[left] < str[right]) return false;
  if (str[left] > str[right]) return true;
  return query(str, left + 1, right - 1);
}

int main(void) {
  fastio;
  int n;
  char c;
  string input, ans;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> c;
    input.push_back(c);
  }

  int left = 0, right = input.size() - 1;
  while (left <= right)
  {
    if(query(input, left, right)) ans.push_back(input[right--]);
    else ans.push_back(input[left++]);
  }

  for (int i = 0; i < ans.size(); i++)
  {
    if(i % 80 == 0 && i != 0) cout << endl;
    cout << ans[i];
  }
  

  return 0;
}