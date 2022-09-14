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
  vector<pair<int, int>> lines(n);
  for (int i = 0; i < n; ++i) {
    cin >> lines[i].first >> lines[i].second;
  }
  sort(lines.begin(), lines.end());

  int ans = lines[0].second - lines[0].first;
  int ns = lines[0].first;
  int ne = lines[0].second;
  for (int i = 1; i < n; ++i) {
    auto curLine = lines[i];
    if (curLine.first >= ne) {
      ans += curLine.second - curLine.first;
      ns = curLine.first;
      ne = curLine.second;
    } else if (ne < curLine.second) {
      ans += curLine.second - ne;
      ns = curLine.first;
      ne = curLine.second;
    }
  }

  cout << ans;

  return 0;
}