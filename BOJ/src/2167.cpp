/***********************************
> File Name: 2167.cpp
> Author: Kadrick
> Created Time: 2021/09/20 01:09
> Description: implement
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
    }
  }

  int q, input[4], sum = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    sum = 0;
    for (int j = 0; j < 4; ++j) {
      cin >> input[j];
      input[j]--;
    }

    for (int j = input[0]; j <= input[2]; ++j) {
      for (int k = input[1]; k <= input[3]; ++k) {
        sum += board[j][k];
      }
    }

    cout << sum << endl;
  }

  return 0;
}