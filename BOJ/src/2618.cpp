/***********************************
> File Name: 2618.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/02 02:36
> Description: DP
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

#define x first
#define y second
#define pii pair<int, int>

int N, W;
int dp[1001][1001];
vector<pii> Case;

int getDist(pii src, pii dest)
{
  return abs(src.x - dest.x) + abs(src.y - dest.y);
}

int solve(int a, int b)
{
  if (a == W + 1 || b == W + 1)
    return 0;

  int &ret = dp[a][b];
  if (ret != -1)
    return ret;

  int nextCase = max(a, b) + 1;

  ret = min(solve(nextCase, b) + getDist(Case[a], Case[nextCase]),
            solve(a, nextCase) + getDist(Case[b], Case[nextCase]));

  return ret;
}

void trace(int a, int b)
{
  if (a == W + 1 || b == W + 1)
    return;

  int nextCase = max(a, b) + 1;

  int choiceA = solve(nextCase, b) + getDist(Case[a], Case[nextCase]);
  int choiceB = solve(a, nextCase) + getDist(Case[b], Case[nextCase]);

  if (choiceA < choiceB)
  {
    cout << 1 << endl;
    trace(nextCase, b);
  }
  else
  {
    cout << 2 << endl;
    trace(a, nextCase);
  }
}

int main(void)
{
  fastio;

  cin >> N >> W;
  memset(dp, -1, sizeof(dp));
  Case.push_back({1, 1});
  Case.push_back({N, N});
  for (int i = 0; i < W; i++)
  {
    int x, y;
    cin >> x >> y;
    Case.push_back({x, y});
  }

  cout << solve(0, 1) << endl;
  trace(0, 1);

  return 0;
}