/**
 * @file 25178.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief string
 * @version 0.1
 * @date 2022-05-16 20:51
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
string a, b;

int main(void)
{
  fastio;

  cin >> n >> a >> b;

  if (a[0] == b[0] && a[n - 1] == b[n - 1])
  {
    vector<char> withoutA, withoutB;
    vector<int> cntA(26, 0), cntB(26, 0);

    for (int i = 0; i < n; i++)
    {
      if (!(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'))
        withoutA.push_back(a[i]);
      if (!(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'))
        withoutB.push_back(b[i]);

      cntA[a[i] - 'a']++;
      cntB[b[i] - 'a']++;
    }

    if (withoutA == withoutB)
    {
      if (cntA == cntB)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    else
      cout << "NO" << endl;
  }
  else
    cout << "NO" << endl;

  return 0;
}