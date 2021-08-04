#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int m, n;
vector<int> ans;
vector<int> arr;
void track(vector<int> &print) {
  if (print.size() == n) {
    for (auto &i : print)
      cout << i << ' ';
    cout << endl;
    return;
  }

  for (int i = 0; i < m; ++i) {
    print.push_back(arr[i]);
    track(print);
    print.pop_back();
  }
}

int main(void) {
  fastio;

  cin >> m >> n;
  arr.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  track(ans);

  return 0;
}