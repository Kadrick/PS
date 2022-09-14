/***********************************
> File Name: 4792.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/10/14 17:40
> Description: MST & disjoint set
***********************************/
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, m, k;
char c;
int f, t;

int parent[1001];

int find(int x)
{
  if (parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u != v)
  {
    parent[v] = u;
    return true;
  }
  return false;
}

typedef struct _Edge
{
  char color;
  int src, dest;
	_Edge(int y, int z, char x) : color(x), src(y), dest(z) {};
} edge;

vector<edge> edges;

bool compFR(const edge &left, const edge &right)
{
  return left.color > right.color;
}
bool compFB(const edge &left, const edge &right)
{
  return left.color < right.color;
}

int mst()
{
  int useBlue = 0, cnt = 0;

  for (auto &e : edges)
  {
    if (merge(e.src, e.dest))
    {
      if (e.color == 'B')
        useBlue++;
      cnt++;
    }
    if (cnt == n - 1)
      break;
  }

  return useBlue;
}

int main(void)
{
  fastio;

  while (true)
  {
    edges.clear();
    cin >> n >> m >> k;
    if (n == 0 && m == 0 && k == 0)
      break;


    for (int i = 0; i < m; i++)
    {
      cin >> c >> f >> t;
      edges.push_back(edge( f,t,c ));
    }

    for (int i = 0; i < n; i++)
      parent[i + 1] = i + 1;
    // minBlue
    sort(edges.begin(), edges.end(), compFR);
    int minB = mst();

    for (int i = 0; i < n; i++)
      parent[i + 1] = i + 1;

    // maxBlue
    sort(edges.begin(), edges.end(), compFB);
    int maxB = mst();

    if (minB <= k && k <= maxB)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}