#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c && c == 60) {
    cout << "Equilateral";
  } else if (a + b + c == 180 && a == b || b == c || c == a) {
    cout << "Isosceles";
  } else if (a + b + c == 180 && a != b && b != c && c != a) {
    cout << "Scalene";
  } else {
    cout << "Error";
  }

  return 0;
}