#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
  int a = x1 * y2 + x2 * y3 + x3 * y1;
  int b = y1 * x2 + y2 * x3 + y3 * x1;
  return a - b;
}

int main(void) {
  fastio;

  int input[6];
  for (int i = 0; i < 6; ++i) {
    cin >> input[i];
  }

  int d = ccw(input[0], input[1], input[2], input[3], input[4], input[5]);

  if (d > 0)
    cout << 1;
  if (d == 0)
    cout << 0;
  if (d < 0)
    cout << -1;

  return 0;
}