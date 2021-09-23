/***********************************
> File Name: 3460.cpp
> Author: Kadrick
> Created Time: 2021/09/20 22:53
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

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;

    int i = 0;
    while (n) {
      if (n % 2)
        cout << i << ' ';
      n /= 2;
      i++;
    }

    cout << endl;
  }

  return 0;
}