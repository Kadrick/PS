/***********************************
> File Name: 4195.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/28 15:50
> Description: disjoint set
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, cnt;
string person[2];
map<string, int> people;
int parent[200001], countNode[200001];

int find(int a)
{
  if (parent[a] == a)
    return a;
  return parent[a] = find(parent[a]);
}

int merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u != v)
  {
    parent[v] = u;
    countNode[u] += countNode[v];
    countNode[v] = 1;
  }
  return countNode[u];
}

int main(void)
{
  fastio;

  int tc;
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    cnt = 0;

    for (int i = 0; i < 2 * n; i++)
    {
      parent[i] = i;
      countNode[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 2; j++)
        cin >> person[j];

      if (people.find(person[0]) == people.end())
      {
        people.insert({person[0], cnt});
        cnt++;
      }
      if (people.find(person[1]) == people.end())
      {
        people.insert({person[1], cnt});
        cnt++;
      }

      cout << merge(people[person[0]], people[person[1]]) << endl;
    }

    people.clear();
  }

  return 0;
}