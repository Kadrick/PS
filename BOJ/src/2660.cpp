/***********************************
> File Name: 2660.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/14 02:29
> Description: Floyd-Warshall
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, u, v, INF = 1e9, ansMin = INF;
vector<vector<int>> point;
vector<int> ans;

int main(void)
{
  fastio;

  cin >> n;

  point.resize(n + 1, vector<int>(n + 1, INF));
  ans.resize(n + 1, 0);

  while (true)
  {
    cin >> u >> v;
    if (u == v && v == -1)
      break;
    point[u][v] = 1;
    point[v][u] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (point[i][j] > point[i][k] + point[k][j])
          point[i][j] = point[i][k] + point[k][j];
      }
    } 
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        continue;
      ans[i] = max(ans[i], point[i][j]);
    }
    ansMin = min(ansMin, ans[i]);
  }

  vector<int> candidate;
  for (int i = 1; i <= n; i++)
    if (ans[i] == ansMin)
      candidate.push_back(i);

  cout << ansMin << ' ' << candidate.size() << endl;
  for (auto &person : candidate)
    cout << person << ' ';

  return 0;
}