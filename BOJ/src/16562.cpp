/**
 * @file 16562.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-10-13 14:28
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

int findParent(vector<int> &parent, int root)
{
    if (root == parent[root])
        return root;
    return parent[root] = findParent(parent, parent[root]);
}

bool merge(vector<int> &cost, vector<int> &parent, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v)
    {
        if (cost[u] < cost[v])
            parent[v] = u;
        else
            parent[u] = v;
        return true;
    }

    return false;
}

int main(void)
{
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(cost, parent, u - 1, v - 1);
    }

    vector<bool> isAdd(n, false);
    for (int i = 0; i < n; i++)
        isAdd[findParent(parent, i)] = true;

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (isAdd[i])
            total += cost[i];
    }

    if (k < total)
        cout << "Oh no" << endl;
    else
        cout << total << endl;

    return 0;
}