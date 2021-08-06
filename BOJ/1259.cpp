#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  while (true) {
    string str;
    cin >> str;
    if (str == "0")
      break;

    while (str.size()) {
      if (str.size() == 1) {
        cout << "yes" << endl;
        break;
      }

      if (str.front() == str.back()) {
        if (str.size() == 2) {
          cout << "yes" << endl;
          break;
        }
        str = str.substr(1);
        str.pop_back();
      } else {
        cout << "no" << endl;
        break;
      }
    }
  }

  return 0;
}