#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int a, b;
int ans_size = 987654321;
string ans;
bool isVisited[10000];

void bfs() {
  queue<pair<int, string>> q;
  q.push(make_pair(a, ""));

  while (!q.empty()) {

    pair<int, string> cur = q.front();
    q.pop();

    int tNum = cur.first;
    string stack = cur.second;

    if (tNum == b) {
      if (stack.length() < ans_size) {
        ans = stack;
        ans_size = stack.length();
      }
    }

    if (stack.length() > ans_size) {
      continue;
    }

    int movenum;

    // case 1 : 두 배로 바꾸기
    movenum = tNum * 2 % 10000;

    if (!isVisited[movenum]) {
      isVisited[movenum] = true;
      stack.push_back('D');
      q.push(make_pair(movenum, stack));
      stack.pop_back();
    }

    // case 2 : 1 빼기
    movenum = tNum - 1;
    if (movenum == -1)
      movenum = 9999;

    if (!isVisited[movenum]) {
      isVisited[movenum] = true;
      stack.push_back('S');
      q.push(make_pair(movenum, stack));
      stack.pop_back();
    }

    // case 3 : L 회전
    movenum = (tNum % 1000) * 10 + tNum / 1000;

    if (!isVisited[movenum]) {
      isVisited[movenum] = true;
      stack.push_back('L');
      q.push(make_pair(movenum, stack));
      stack.pop_back();
    }

    // case 4 : R 회전
    movenum = (tNum % 10) * 1000 + tNum / 10;

    if (!isVisited[movenum]) {
      isVisited[movenum] = true;
      stack.push_back('R');
      q.push(make_pair(movenum, stack));
      stack.pop_back();
    }
  }
}

int main(void) {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    ans = "";
    ans_size = 1000000000;
    memset(isVisited, false, sizeof(isVisited));
    cin >> a >> b;
    bfs();

    cout << ans << endl;
  }

  return 0;
}