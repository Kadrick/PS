#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  vector<int> asc(8);
  vector<int> des(8);
  vector<int> arr(8);

  for (int i = 0; i < 8; ++i) {
    cin >> arr[i];
    asc[i] = i + 1;
    des[i] = 8 - i;
  }

  if (arr == asc) {
    cout << "ascending" << endl;
  } else if (arr == des) {
    cout << "descending" << endl;
  } else {
    cout << "mixed" << endl;
  }

  return 0;
}