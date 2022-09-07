/**
 * @file 10423.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief kruskal
 * @version 0.1
 * @date 2022-09-07 13:14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

bool comp(
    const pair<int, pair<int, int>> &left,
    const pair<int, pair<int, int>> &right)
{
    return left.first < right.first;
}

int findParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

bool merge(vector<int> &parent, int x, int y)
{
    x = findParent(parent, x);
    y = findParent(parent, y);

    if (x == y)
        return false;

    parent[min(x, y)] = max(x, y);
    return true;
}

int main(void)
{
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(n + 1, 0);
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < n + 1; i++)
        parent[i] = i;

    for (int i = 0; i < k; i++)
    {
        int lab;
        cin >> lab;
        parent[lab] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end(), comp);

    int ans = 0;
    for (auto &&edge : edges)
    {
        int cost = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (merge(parent, from, to))
            ans += cost;
    }

    cout << ans << endl;

    return 0;
}