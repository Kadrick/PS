#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n;
  cin >> n;

  int ans = 0, tmp;
  vector<int> ansArr;

  for (int i = 1; i <= n; ++i) {
    vector<int> arr;
    tmp = n;
    arr.push_back(n);
    arr.push_back(i);
    for (int j = 2; tmp >= 0; ++j) {
      tmp = arr[j - 2] - arr[j - 1];
      arr.push_back(tmp);
    }
    arr.pop_back();
    if (arr.size() > ans) {
      ansArr = arr;
      ans = arr.size();
    }
  }

  cout << ans << endl;
  for (auto i : ansArr) {
    cout << i << ' ';
  }

  return 0;
}