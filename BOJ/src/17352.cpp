/**
 * @file 17352.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-10-14 17:11
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

    int n;
    cin >> n;

    vector<int> parent(n + 1, 0);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < n - 2; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(parent, u, v);
    }

    int one = findParent(parent, 1);
    for (int i = 2; i <= n; i++)
    {
        if (findParent(parent, i) != one)
        {
            cout << 1 << ' ' << i << endl;
            break;
        }
    }

    return 0;
}