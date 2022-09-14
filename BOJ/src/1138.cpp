#include <algorithm>
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
  vector<int> cntTall(n);
  vector<int> height(n);
  for (int i = 0; i < n; ++i) {
    cin >> cntTall[i];
    height[i] = i;
  }

  do {
    bool check = true;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < i; ++j) {
        if (height[i] < height[j])
          cnt++;
      }
      if (cntTall[height[i]] != cnt) {
        check = false;
        break;
      }
    }
    if (check) {
      for (auto i : height)
        cout << i + 1 << ' ';
      break;
    }
  } while (next_permutation(height.begin(), height.end()));

  return 0;
}