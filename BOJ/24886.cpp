/**
 * @file 24886.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement, string
 * @version 0.1
 * @date 2022-05-09 20:12
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

int len, scap, kcap, hcap, ans;
string input;

int skcnt, khcnt, shcnt;
int scnt, kcnt, hcnt;

int main(void)
{
  fastio;

  cin >> len >> scap >> kcap >> hcap >> input;

  // 원래 문자열에서 skh, sk, kh, sh, s, k, h 개수 세기
  for (int i = 0; i < len; i++)
  {
    if (i + 2 < len && input[i] == 'S' && input[i + 1] == 'K' && input[i + 2] == 'H')
    {
      ans++;
      i += 2;
    }
    else if (i + 1 < len && input[i] == 'S' && input[i + 1] == 'K')
    {
      skcnt++;
      i += 1;
    }
    else if (i + 1 < len && input[i] == 'K' && input[i + 1] == 'H')
    {
      khcnt++;
      i += 1;
    }
    else if (i + 1 < len && input[i] == 'S' && input[i + 1] == 'H')
    {
      shcnt++;
      i += 1;
    }
    else if (input[i] == 'S')
      scnt++;
    else if (input[i] == 'K')
      kcnt++;
    else if (input[i] == 'H')
      hcnt++;
  }

  // s, h, k 붙이기
  ans += min(skcnt, hcap);
  hcap -= min(skcnt, hcap);

  ans += min(khcnt, scap);
  scap -= min(khcnt, scap);

  ans += min(shcnt, kcap);
  kcap -= min(shcnt, kcap);

  // kh, sk, sh 붙이기
  int addv = 0;

  int up = min({scnt, kcap, hcap});
  for (int use = 0; use <= up; use++)
  {
    int ktosh = min({kcnt, scap, hcap - use});
    int htosk = min({hcnt, scap - ktosh, kcap - use});
    int skh = min({scap - htosk - ktosh, kcap - use - htosk, hcap - use - ktosh});
    addv = max(addv, use + ktosh + htosk + skh);
  }

  up = min({scap, kcnt, hcap});
  for (int use = 0; use <= up; use++)
  {
    int stokh = min({scnt, kcap, hcap - use});
    int htosk = min({hcnt, kcap - stokh, scap - use});
    int skh = min({scap - use - htosk, kcap - stokh - stokh, hcap - use - stokh});
    addv = max(addv, use + stokh + htosk + skh);
  }

  up = min({scap, kcap, hcnt});
  for (int use = 0; use <= up; use++)
  {
    int stokh = min({scnt, kcap - use, hcap});
    int ktosh = min({kcnt, scap - use, hcap - stokh});
    int skh = min({scap - use - ktosh, kcap - use - stokh, hcap - stokh - ktosh});
    addv = max(addv, use + stokh + ktosh + skh);
  }

  ans += addv;
  cout << ans << endl;

  return 0;
}