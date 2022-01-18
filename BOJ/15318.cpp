/**
 * @file 15318.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief prefix sum
 * @version 0.1
 * @date 2022-01-18 23:34
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

int n, dir[2] = {1, -1};
vector<long long> arr;
vector<long long> ans;
vector<long long> tmp;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n, 0);
  ans.resize(n, 0);
  tmp.resize(n, 0);

  for (int i = 0; i < n; ++i)
  	cin >> arr[i];
  
  // answer_0
  for (int k = 0; k < n; k++)
    ans[0] += dir[k % 2] * (k + 1) * arr[k];
  
  // tmp_0
  for (int k = 1; k < n; k++)
    tmp[0] += dir[k % 2] * arr[k];

  // fill tmp
  for (int i = 0; i < n - 1; i++)
    tmp[i + 1] = dir[(n - 1) % 2] * arr[i] - arr[i + 1] - tmp[i];
  
  // fill answer
  for (int i = 1; i < n; i++)
  {
    ans[i] = tmp[i - 1] - ans[i - 1] + arr[i - 1] 
              + dir[(n - 1) % 2] * n * arr[i - 1];
  }
  
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;

  return 0;
}
