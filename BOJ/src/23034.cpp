/**
 * @file 23034.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-12-12 11:07
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

int findParent(vector<int> &parent, int child)
{
    if (parent[child] == child)
        return child;
    return parent[child] = findParent(parent, parent[child]);
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

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1, 0);
    for (int i = 0; i < n; i++)
        parent[i + 1] = i + 1;

    int total = 0;
    vector<vector<pair<int, int>>> tree(n + 1);
    for (auto &&edge : edges)
    {
        if (merge(parent, edge.second.first, edge.second.second))
        {
            total += edge.first;
            tree[edge.second.first].push_back({edge.second.second, edge.first});
            tree[edge.second.second].push_back({edge.second.first, edge.first});
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        vector<int> visited(n + 1, false);
        queue<pair<int, int>> q;
        q.push({x, 0});
        visited[x] = true;

        int maxCost = 0;
        while (!q.empty())
        {
            auto here = q.front();
            q.pop();

            if (here.first == y)
            {
                maxCost = here.second;
                break;
            }

            for (auto &&next : tree[here.first])
            {
                if (!visited[next.first])
                {
                    visited[next.first] = true;
                    q.push({next.first, max(here.second, next.second)});
                }
            }
        }

        cout << total - maxCost << endl;
    }

    return 0;
}