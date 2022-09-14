// author : kadrick
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n;

string twoTimes(string src) {
  int carry = 0, add = 0;
  for (int i = src.size() - 1; i >= 0; --i) {
    int num = src[i] - '0';
    add = (num * 2 + carry) % 10;
    carry = (num * 2 + carry) / 10;
    src[i] = add + '0';
  }
  if (carry)
    src = (char)(carry + '0') + src;
  return src;
}

void hanoi(int n, int src, int r, int dest) {
  if (n == 1) {
    cout << src << ' ' << dest << endl;
  } else {
    hanoi(n - 1, src, dest, r);
    cout << src << ' ' << dest << endl;
    hanoi(n - 1, r, src, dest);
  }
}
int main(void) {
  fastio;

  cin >> n;
  if (n <= 20) {
    cout << fixed; cout.precision(0);
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 1, 2, 3);
  } else {
    int tmp = pow(2, 20);
    string src = to_string(tmp);

    for (int i = 0; i < n - 20; ++i) {
      src = twoTimes(src);
    }

    src[src.size() - 1] -= 1;
    cout << src;
  }

  return 0;
}