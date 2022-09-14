/**
 * @file 16496.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sorting
 * @version 0.1
 * @date 2022-03-08 04:02
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

int n;
vector<int> arr;

bool comp(int& left, int& right) {
  string first = to_string(left) + to_string(right);
  string second = to_string(right) + to_string(left);
  return first > second;
}

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end(), comp);

  if(arr[0] == 0)
    cout << 0 << endl;
  else {
    for(auto& number : arr)
      cout << number;
    cout << endl;
  }
  
  return 0;
}