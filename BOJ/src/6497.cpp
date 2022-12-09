/**
 * @file 6497.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-12-09 10:57
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

int findParent(vector<int> &arr, int target)
{
    if (arr[target] == target)
        return target;
    return arr[target] = findParent(arr, arr[target]);
}

bool merge(vector<int> &arr, int u, int v)
{
    u = findParent(arr, u);
    v = findParent(arr, v);

    if (u != v)
    {
        arr[max(u, v)] = min(u, v);
        return true;
    }
    return false;
}

int main(void)
{
    fastio;

    while (true)
    {
        int m, n, total = 0;
        cin >> m >> n;

        if (m == n && m == 0)
            break;

        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({z, {x, y}});
            total += z;
        }

        vector<int> parent(m, 0);
        for (int i = 0; i < m; i++)
            parent[i] = i;

        sort(edges.begin(), edges.end());

        int consume = 0;

        for (auto &&edge : edges)
        {
            if (merge(parent, edge.second.first, edge.second.second))
                consume += edge.first;
        }

        cout << total - consume << endl;
    }

    return 0;
}