#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
vector<int> arr;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int target;
    cin >> target;

    cout << upper_bound(arr.begin(), arr.end(), target) -
                lower_bound(arr.begin(), arr.end(), target);
    cout << ' ';
  }

  return 0;
}