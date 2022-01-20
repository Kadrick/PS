/**
 * @file 1185.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-01-20 17:03
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

int n, p, ans, start = INT32_MAX;
vector<int> cost, parent, height;
vector<pair<int, pair<int, int>>> edge;

int find(int node)
{
	if (node == parent[node])
		return node;

	return parent[node] = find(parent[node]);
}

void merge(int node1, int node2)
{
	node1 = find(node1);
	node2 = find(node2);

	if (node1 == node2)
		return;

	if (height[node1] < height[node2])
		parent[node1] = node2;

	else
	{
		parent[node2] = node1;

		if (height[node1] == height[node2])
			height[node1]++;
	}
}

int main(void)
{
  fastio;

  cin >> n >> p;

  cost.resize(n + 1, 0);
  parent.resize(n + 1, 0);
  height.resize(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> cost[i + 1];
    start = min(start, cost[i + 1]);
  }

  for (int i = 0; i < p; i++)
  {
    int s, e, l;
    cin >> s >> e >> l;
    edge.push_back({l * 2 + cost[s] + cost[e], {s , e}});
  }
  
  sort(edge.begin(), edge.end());

  for (int i = 1; i <= n; i++)
    parent[i] = i;

  for (int i = 0; i < edge.size(); i++)
  {
    int u = edge[i].second.first;
    int v = edge[i].second.second;
    int c = edge[i].first;

    if(find(u) != find(v)) {
      merge(u, v);
      ans += c;
    } 
  }
  
  cout << ans + start << endl;

  return 0;
}