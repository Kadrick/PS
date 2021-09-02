#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, ans_idx = 1;
int arr[1001];
int dp[1001];
int parent[1001];

void printArr(int cur) {
  if (parent[cur])
    printArr(parent[cur]);
  cout << arr[cur] << ' ';
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i + 1];
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (arr[i] > arr[j] && dp[i] <= dp[j]) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
        if (dp[i] > dp[ans_idx]) {
          ans_idx = i;
        }
      }
    }
  }

  cout << dp[ans_idx] + 1 << endl;
  printArr(ans_idx);

  return 0;
}