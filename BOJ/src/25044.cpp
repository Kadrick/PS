/**
 * @file 25044.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief  implement
 * @version 0.1
 * @date 2022-05-03 10:23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, k, idx, cur;
int add[5] = {15 * 60, 3 * 60, 3 * 60, 0, 3 * 60};
vector<int> ans;

void print(int min)
{
  printf("%02d:%02d\n", min / 60, min % 60);
}

int main(void)
{
  // fastio;

  scanf("%d %d", &n, &k);

  add[3] = k;
  int left = 24 * 60 * n;
  int right = 24 * 60 * (n + 1);

  // simulate
  while (cur + add[idx] < right)
  {
    cur += add[idx];
    if (left <= cur && idx < 3)
      ans.push_back(cur);

    idx += 1;
    idx %= 5;
  }

  cout << ans.size() << endl;
  for (auto &&time : ans)
    print(time - left);

  return 0;
}