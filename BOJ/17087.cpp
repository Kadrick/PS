/***********************************
> File Name: 17087.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/12 21:22
> Description: math
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, s, input;
vector<int> dist;

int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int main(void)
{
  fastio;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    dist.push_back(abs(input - s));
  }

  int ans = dist[0];
  for (int i = 1; i < dist.size(); i++)
    ans = gcd(ans, dist[i]);

  cout << ans;

  return 0;
}