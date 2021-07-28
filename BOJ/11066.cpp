#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

long long cache[501][501];
long long ans[501][501];
int arr[501];
int n;

long long findAns(int start, int end) {
  if (start == end)
    return ans[start][end];

  long long &ret = ans[start][end];
  if (ret != -1)
    return ret;

  long long pivot = cache[start][end];
  ret = LONG_LONG_MAX;
  for (int i = start; i < end; ++i) {
    if (pivot == cache[start][i] + cache[i + 1][end]) {
      ret = min(ret, pivot + findAns(start, i) + findAns(i + 1, end));
    }
  }
  return ret;
}

long long solve(int start, int end) {
  if (start == end)
    return cache[start][end];

  long long &ret = cache[start][end];
  if (ret != -1)
    return ret;

  ret = LONG_LONG_MAX;
  for (int i = start; i < end; ++i) {
    long long tmp = solve(start, i) + solve(i + 1, end);
    if (tmp <= ret) {
      ret = tmp;
    }
  }
  return ret;
}

int main(void) {
  fastio;

  int t;
  cin >> t;
  for (int test_case = 0; test_case < t; ++test_case) {
    memset(cache, -1, sizeof(cache));
    memset(ans, -1, sizeof(ans));

    cin >> n;

    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      cache[i][i] = arr[i];
      ans[i][i] = 0;
    }

    solve(1, n);

    findAns(1, n);

    cout << findAns(1, n) << endl;
  }

  return 0;
}