#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;
vector<int> arr;
vector<int> L;

int main(void) {
  fastio;

  cin >> n;
  arr.resize(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; ++i) {
    int here = lower_bound(L.begin(), L.end(), arr[i]) - L.begin();
    if (here == L.size())
      L.push_back(arr[i]);
    else
      L[here] = arr[i];
  }

  cout << L.size();

  return 0;
}