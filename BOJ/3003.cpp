#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  vector<int> arr(6, 0);
  vector<int> ans(6, 0);
  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 2;
  ans[4] = 2;
  ans[5] = 8;

  for (int i = 0; i < 6; ++i) {
    cin >> arr[i];
    cout << ans[i] - arr[i] << ' ';
  }

  return 0;
}