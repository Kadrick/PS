#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, m;
map<string, int> see;
vector<string> ans;

int main(void) {
  fastio;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    see[tmp] = i;
  }

  for (int i = 0; i < m; ++i) {
    string tmp;
    cin >> tmp;
    if (see.find(tmp) != see.end()) {
      ans.push_back(tmp);
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto str : ans)
    cout << str << endl;

  return 0;
}