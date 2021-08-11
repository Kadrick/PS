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
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    ans += (long long)arr[i] * (n - i);
  }

  cout << ans;

  return 0;
}