/***********************************
> File Name: 13334.cpp
> Author: Kadrick, Bo Gwon Kang
> Created Time: 2021/09/23 14:26
> Description: Sweep
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, ans, cnt;
long long d;
vector<pair<int, int>> input, range;

int main(void) {
  fastio;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    int h, o;
    cin >> h >> o;
      if (h > o)
        swap(h, o);
      input.push_back(make_pair(h, o));
  }

  cin >> d;

  for (auto pii : input) {
    if(pii.second - pii.first > d) continue;
    range.push_back(make_pair(pii.first, 1));
    range.push_back(make_pair(pii.second - d, -1));
  }

  sort(range.begin(), range.end());

  for (auto pii : range) {
    //cout << pii.first << ' ' << pii.second << endl;
    cnt -= pii.second;
    ans = max(ans, cnt);
  }

  cout << ans;

  return 0;
}