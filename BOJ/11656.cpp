#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  string input;
  cin >> input;
  vector<string> arr;

  for (int i = 0; i < input.size(); ++i) {
    arr.push_back(input.substr(i));
  }

  sort(arr.begin(), arr.end());

  for (auto &&str : arr) {
    cout << str << endl;
  }

  return 0;
}