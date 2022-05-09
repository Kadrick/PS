/**
 * @file 24883.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-05-09 20:03
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

int main(void)
{
  fastio;

  char c;
  cin >> c;

  if (c == 'N' || c == 'n')
    cout << "Naver D2" << endl;
  else
    cout << "Naver Whale" << endl;

  return 0;
}