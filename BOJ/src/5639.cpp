/***********************************
> File Name: 5639.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/29 13:34
> Description: Tree
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int input;
vector<int> arr;

void post(int left, int right)
{
  // here node is left
  int ans = left;
  // fence left / right
  int fence = left;

  // left + 1 ~ fence is smaller than root
  while (++fence <= arr.size() - 1 && arr[fence] < arr[ans])
    ;

  // left sub tree
  if (left + 1 <= fence - 1)
    post(left + 1, fence - 1);
  // right sub tree
  if (fence <= right)
    post(fence, right);

  // print root;
  cout << arr[ans] << endl;
}

int main(void)
{
  fastio;

  while (cin >> input)
    arr.push_back(input);

  post(0, arr.size() - 1);

  return 0;
}