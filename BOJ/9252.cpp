#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int dp[1001][1001];
int parent[1001][1001];
string A, B;

string print(int y, int x) {
  string ret = "";
  int flag = parent[y][x];
  if (flag == 3) {
    ret += print(y - 1, x - 1);
    ret += A[y - 1];
  } else if (flag == 2) {
    ret += print(y, x - 1);
  } else if (flag == 1) {
    ret += print(y - 1, x);
  }
  return ret;
}

int main(void) {
  fastio;

  string ans;
  int cnt = 0;
  cin >> A >> B;

  for (int i = 1; i <= A.length(); ++i) {
    for (int j = 1; j <= B.length(); ++j) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        parent[i][j] = 3;
        cnt = max(cnt, dp[i][j]);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (dp[i][j] == dp[i - 1][j])
          parent[i][j] = 1;
        else
          parent[i][j] = 2;
      }
    }
  }

  cout << cnt << endl;
  cout << print(A.length(), B.length());

  return 0;
}