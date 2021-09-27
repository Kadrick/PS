/***********************************
> File Name: 2309.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/27 02:58
> Description: sorting
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int arr[9], sum, flag;

void print(int no1, int no2) {
  for (int i = 0; i < 9; ++i) {
    if (i == no1 || no2 == i)
      continue;
    cout << arr[i] << endl;
  }
}

int main(void) {
  fastio;

  for (int i = 0; i < 9; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }

  sort(arr, arr + 9);

  for (int i = 0; i < 9; ++i) {
    sum -= arr[i];
    for (int j = 0; j < 9; ++j) {
      if (i != j && sum - arr[j] == 100) {
        flag = 1;
        print(i, j);
      }
    }
    if (flag)
      break;
    sum += arr[i];
  }

  return 0;
}