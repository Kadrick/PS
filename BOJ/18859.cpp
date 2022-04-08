/**
 * @file 18859.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sorting
 * @version 0.1
 * @date 2022-04-08 13:16
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

int n;
multiset<int> arr;

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    arr.insert(tmp);
  }

  int first = *(arr.begin());
  arr.erase(arr.begin());

  int tolerance = *(arr.begin()) - first;
  if (tolerance == 0)
  {
    cout << "No" << endl;
    return 0;
  }

  int last;

  int value = first;
  while (arr.size())
  {
    value += tolerance;
    auto pos = arr.find(value);
    if (pos != arr.end())
      arr.erase(pos);
    else
    {
      last = value - tolerance;
      break;
    }
  }

  if (arr.size() <= 1)
  {
    cout << "Yes" << endl;
    return 0;
  }

  int cnt = 0;
  tolerance = *(arr.begin()) - first;
  value = first;
  while (arr.size())
  {
    value += tolerance;
    auto pos = arr.find(value);
    if (pos != arr.end())
      cnt++;
    else
      break;
  }

  if (cnt == arr.size())
  {
    cout << "Yes" << endl;
    return 0;
  }

  arr.insert(last);
  cnt = 0;
  tolerance = *(arr.begin()) - first;
  value = first;
  while (arr.size())
  {
    value += tolerance;
    auto pos = arr.find(value);
    if (pos != arr.end())
      cnt++;
    else
      break;
  }

  if (cnt == arr.size())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}