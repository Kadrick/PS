/***********************************
> File Name: 1786.cpp
> Author: Kadrick
> Created Time: 2021/09/17 18:38
> Description: KMP Algorithm
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

vector<int> setFail(string find) {
  int length = find.size();
  int j = 0;
  vector<int> ret(length, 0);

  for (int i = 1; i < length; ++i) {
    while (j > 0 && find[i] != find[j]) {
      j = ret[j - 1];
    }
    if (find[i] == find[j])
      ret[i] = ++j;
  }

  return ret;
}

vector<int> kmp(string input, string find) {
  vector<int> ret;
  vector<int> fail = setFail(find);
  int j = 0;

  for (int i = 0; i < input.size(); ++i) {
    while (j > 0 && input[i] != find[j]) {
      j = fail[j - 1];
    }
    if (input[i] == find[j]) {
      if (j == find.size() - 1) {
        ret.push_back(i - find.size() + 1);
        j = fail[j];
      } else {
        ++j;
      }
    }
  }

  return ret;
}

int main(void) {
  fastio;
  string input, find;
  getline(cin, input);
  getline(cin, find);

  vector<int> ret = kmp(input, find);
  cout << ret.size() << endl;
  for (auto pos : ret) {
    cout << pos + 1 << ' ';
  }

  return 0;
}