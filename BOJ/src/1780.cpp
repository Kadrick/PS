#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

vector<vector<int>> paper;
int negative, zero, positive;

void solve(int y, int x, int N) {
  bool isOnePaper = true;
  int flag = paper[y][x];
  for (int i = y; i < y + N; ++i) {
    for (int j = x; j < x + N; ++j) {
      if (paper[i][j] != flag) {
        isOnePaper = false;
        break;
      }
    }
    if (!isOnePaper)
      break;
  }

  if (isOnePaper) {
    if (flag == -1)
      negative++;
    else if (flag == 0)
      zero++;
    else
      positive++;
  } else {
    for (int i = y; i < y + N; i += N / 3) {
      for (int j = x; j < x + N; j += N / 3) {
        solve(i, j, N / 3);
      }
    }
  }
}

int main(void) {
  fastio

      int N;
  cin >> N;
  paper.resize(N, vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> paper[i][j];
    }
  }

  solve(0, 0, N);

  cout << negative << endl;
  cout << zero << endl;
  cout << positive << endl;

  return 0;
}