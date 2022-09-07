/**
 * @file 14621.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-09-07 13:38
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

    parent[max(x, y)] = min(x, y);
    return true;
}

int main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1, 0);
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < n + 1; i++)
        parent[i] = i;

    string univ = "N";
    for (int i = 0; i < n; i++)
    {
        char props;
        cin >> props;
        univ.push_back(props);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (univ[u] != univ[v])
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

    bool checkConnect = true;
    for (int i = 1; i < n + 1; i++)
    {
        if (findParent(parent, parent[i]) != 1)
        {
            checkConnect = false;
            break;
        }
    }

    if (checkConnect)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}