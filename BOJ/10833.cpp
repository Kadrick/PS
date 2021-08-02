#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int human, apple;
    cin >> human >> apple;
    ans += apple - (apple / human) * human;
  }
  cout << ans;
  return 0;
}