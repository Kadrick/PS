#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;

    vector<pair<int, string>> arr;
    for (int i = 0; i < n; ++i) {
      string school;
      int drink;
      cin >> school >> drink;
      arr.push_back(make_pair(drink, school));
    }

    sort(arr.begin(), arr.end(), greater<>());

    cout << arr[0].second << endl;
  }
  return 0;
}