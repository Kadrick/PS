#include <bits/stdc++.h>
#include <map>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  multimap<string, int> mm;

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<string> typeArr;
    for (int j = 0; j < n; ++j) {
      string clo, type;
      cin >> clo >> type;
      auto iter = mm.find(type);
      if (iter != mm.end()) {
        iter->second = iter->second + 1;
      } else {
        mm.insert(make_pair(type, 2));
        typeArr.push_back(type);
      }
    }

    int ans = 1;
    for (auto &&type : typeArr) {
      ans *= mm.find(type)->second;
    }
    cout << ans - 1 << endl;
    mm.clear();
  }

  return 0;
}