#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

string add(string a, string b) {
  string ret;
  int carry = 0;
  while (!a.empty() && !b.empty()) {
    int backA = a.back() - '0';
    a.pop_back();
    int backB = b.back() - '0';
    b.pop_back();
    ret.push_back((backA + backB + carry) % 10 + '0');
    carry = (backA + backB + carry) / 10;
  }
  if (a.empty() && b.empty()) {
    if (carry)
      ret.push_back(carry + '0');
  } else if (a.empty()) {
    while (!b.empty()) {
      int backB = b.back() - '0';
      b.pop_back();
      ret.push_back((backB + carry) % 10 + '0');
      carry = (backB + carry) / 10;
    }
    if (carry)
      ret.push_back(carry + '0');
  } else if (b.empty()) {
    while (!a.empty()) {
      int backA = a.back() - '0';
      a.pop_back();
      ret.push_back((backA + carry) % 10 + '0');
      carry = (backA + carry) / 10;
    }
    if (carry)
      ret.push_back(carry + '0');
  }

  for (int i = 0; i < ret.size() / 2; ++i) {
    int tmp = ret[i];
    ret[i] = ret[ret.size() - 1 - i];
    ret[ret.size() - 1 - i] = tmp;
  }

  return ret;
}

int main(void) {
  fastio;

  string a, b;
  cin >> a >> b;

  cout << add(a, b);

  return 0;
}