/**
 * @file 24391.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-10-14 09:24
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

    int n, m;
    cin >> n >> m;

    vector<int> parent(1, 0);
    for (int i = 0; i < n; i++)
        parent.push_back(i + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        merge(parent, u, v);
    }

    int code, before, ans = 0;
    cin >> code;
    before = findParent(parent, code);

    for (int i = 1; i < n; i++)
    {
        cin >> code;
        if (before != findParent(parent, code))
        {
            before = findParent(parent, code);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}