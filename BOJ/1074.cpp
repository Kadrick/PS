#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, R, C;

bool solve(int r, int c, int size, int value) {
  // cout << "r: " << r << " c: " << c;
  // cout << " size: " << size << " value: " << value << endl;

  if (r == R && c == C && size == 1) {
    cout << value << endl;
    return true;
  }

  if (size == 1)
    return false;

  int halfSize = size / 2;
  int unitValue = pow(size, 2) / 4;
  bool res = false;

  //왼쪽 상단
  if (r <= R && R < r + halfSize && c <= C && C < c + halfSize)
    res = solve(r, c, halfSize, value + unitValue * 0);

  //오른쪽 상단
  if (r <= R && R < r + halfSize && c + halfSize <= C && C < c + halfSize * 2)
    res = solve(r, c + halfSize, halfSize, value + unitValue * 1);

  //왼쪽 하단
  if (r + halfSize <= R && R < r + 2 * halfSize && c <= C && C < c + halfSize)
    res = solve(r + halfSize, c, halfSize, value + unitValue * 2);

  //오른쪽 하단
  if (r + halfSize <= R && R < r + 2 * halfSize && c + halfSize <= C &&
      C < c + halfSize * 2)
    res = solve(r + halfSize, c + halfSize, halfSize, value + unitValue * 3);

  return res;
}

int main(void) {
  fastio;

  cin >> n >> R >> C;

  solve(0, 0, 1 << n, 0);

  return 0;
}