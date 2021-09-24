/***********************************
> File Name: 2399.cpp
> Author: Kadrick
> Created Time: 2021/09/24
> Description: implement
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<long long> arr;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += abs(arr[i] - arr[j]);
    }
  }

  cout << ans;

  return 0;
}