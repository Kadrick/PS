/**
 * @file 9359.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-02-17 01:22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++)
  {
    long long a, b, n, ans;
    cin >> a >> b >> n;
    ans = b - a + 1;

    long long tmp = n;
    vector<long long> factor;
    for (long long i = 2; i <= (long long)sqrt(n); i++)
    {
      if(tmp % i == 0) {
        factor.push_back(i);
        while (tmp % i == 0)
          tmp /= i;
      }
    }
    if(tmp != 1)
      factor.push_back(tmp);

    long long sum = 0;
    long long max_bit = 1ll << factor.size();
    for (long long i = 1; i < max_bit; i++)
    {
      long long cnt = 0, mul = 1;
      for (long long j = 0; j < factor.size(); j++)
      {
        if(!(i & (1ll << j)))
          continue;
        mul *= factor[j];
        cnt++;
      }
      long long cnta = (a + mul - 1) / mul;
      long long cntb = b / mul;
      if(cnta > cntb)
        continue;
      if(cnt & 1)
        ans -= cntb - cnta + 1;
      else
        ans += cntb - cnta + 1;
    }
    
    cout << "Case #" << tc + 1 << ": " << ans << endl;
  }
  
  return 0;
}