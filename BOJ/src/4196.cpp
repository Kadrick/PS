/***********************************
> File Name: 4196.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/28
> Description: SCC / Topological sorting
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m;
stack<int> st;
vector<bool> isVisited;
vector<vector<int>> adj;
vector<vector<int>> contrary;
vector<int> sccnum;
vector<int> inDegree;

void createSt(int here)
{
  isVisited[here] = true;

  for (auto &there : adj[here])
  {
    if (!isVisited[there])
      createSt(there);
  }

  st.push(here);
}

void createSCC(int here, int &sccNum)
{
  isVisited[here] = true;

  for (auto &there : contrary[here])
  {
    if (!isVisited[there])
      createSCC(there, sccNum);
  }

  sccnum[here] = sccNum;
}

int main(void)
{
  fastio;

  int tc;
  cin >> tc;
  while (tc--)
  {
    isVisited.clear();
    adj.clear();
    contrary.clear();
    inDegree.clear();
    sccnum.clear();

    cin >> n >> m;

    isVisited.resize(n + 1, false);
    adj.resize(n + 1, vector<int>());
    contrary.resize(n + 1, vector<int>());
    inDegree.resize(n + 1, 0);
    sccnum.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      contrary[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
      if (!isVisited[i])
        createSt(i);

    isVisited.clear();
    isVisited.resize(n + 1, false);

    int num = 1;
    while (!st.empty())
    {
      if (!isVisited[st.top()])
      {
        createSCC(st.top(), num);
        num++;
      }
      st.pop();
    }

    for (int i = 0; i < n; i++)
    {
      for (auto &there : adj[i + 1])
      {
        if (sccnum[i + 1] == sccnum[there])
          continue;
        inDegree[sccnum[there]]++;
      }
    }

    int ans = 0;

    for (int i = 1; i <= num; i++)
    { 
      if (inDegree[i] == 0)
        ans++;
    }

    cout << ans - 1 << endl;
    
  }
  return 0;
}