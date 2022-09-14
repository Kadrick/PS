/***********************************
> File Name: 1107.cpp
> Author: Kadrick
> Created Time: 2021/09/18 15:40
> Description: brute force
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int m, ans, INF = 987654321;
int target;
vector<bool> isPossible(10, true);

bool judge(int num) {
  string test = to_string(num);
  for (int i = 0; i < test.size(); ++i) {
    if (!isPossible[test[i] - '0'])
      return false;
  }
  return true;
}

int main(void) {
  fastio;

  cin >> target >> m;
  for (int i = 0; i < m; ++i) {
    int input;
    cin >> input;
    isPossible[input] = false;
  }

  int distance = abs(target - 100);
  int up = INF, down = INF;

  for (int i = 0;; ++i) {
    if (up != INF || down != INF || m == 10)
      break;
    if (judge(target + i) && up == INF)
      up = i + to_string(target + i).size();
    if (judge(target - i) && down == INF)
      down = i + to_string(target - i).size();
  }

  cout << min({distance, up, down});
  return 0;
}