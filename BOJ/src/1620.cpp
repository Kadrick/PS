#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int N, M;
map<int, string> imap;
map<string, int> smap;

bool isInt(string input) {
  for (auto ch : input) {
    if (!isdigit(ch))
      return false;
  }
  return true;
}

int main(void) {
  fastio;

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    string name;
    cin >> name;
    imap[i] = name;
    smap[name] = i;
  }

  for (int i = 0; i < M; ++i) {
    string input;
    cin >> input;
    if (isInt(input))
      cout << imap[atoi(input.c_str())] << endl;
    else
      cout << smap[input] << endl;
  }

  return 0;
}