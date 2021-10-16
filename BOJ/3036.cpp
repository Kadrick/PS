
/***********************************
> File Name: 3036.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/16 20:23
> Description: math
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n;
int arr[1000];

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 1; i < n; i++)
  {
    int d = gcd(arr[0], arr[i]);
    cout << arr[0] / d << '/' << arr[i] / d << endl;
  }

  return 0;
}