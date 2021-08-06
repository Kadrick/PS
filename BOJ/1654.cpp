#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

long long k, n;
long long ans = 1;
vector<long long> arr;

bool check(long long length) {
  long long sum = 0;
  for (long long i = 0; i < arr.size(); ++i) {
    sum += arr[i] / length;
    if (sum >= n)
      return true;
  }
  return false;
}

int main(void) {
  fastio;

  cin >> k >> n;
  arr.resize(k);
  for (long long i = 0; i < k; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  long long lo = 1, hi = arr.back();

  while (lo <= hi && lo > 0) {
    long long mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid + 1;
      ans = max(ans, mid);
    } else {
      hi = mid - 1;
    }
  }

  cout << ans;

  return 0;
}