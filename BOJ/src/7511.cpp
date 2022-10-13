/**
 * @file 7511.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-10-13 16:18
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

bool merge(vector<int> &parent, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v)
    {
        parent[max(u, v)] = min(u, v);
        return true;
    }

    return false;
}

int main(void)
{
    fastio;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << "Scenario " << i + 1 << ":" << endl;

        int n, k;
        cin >> n >> k;

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            merge(parent, u, v);
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u = findParent(parent, u);
            v = findParent(parent, v);

            if (u == v)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }

        cout << endl;
    }

    return 0;
}