#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}

int main(void) {
  fastio;

  multiset<pair<int, int>> mm;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int order;
    cin >> order;

    if (order == 0) {
      if (mm.size() == 0)
        cout << 0 << endl;
      else {
        cout << mm.begin()->second << endl;
        mm.erase(mm.begin());
      }
    } else {
      mm.insert(make_pair(abs(order), order));
    }
  }

  return 0;
}