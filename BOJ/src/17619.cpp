/**
 * @file 17619.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set + sweep line
 * @version 0.1
 * @date 2022-09-13 11:15
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

int findParent(vector<int> &parent, int target)
{
    if (parent[target] == target)
        return target;
    return parent[target] = findParent(parent, parent[target]);
}

bool merge(vector<int> &parent, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return false;

    parent[max(u, v)] = min(u, v);
    return true;
}

int main(void)
{
    fastio;

    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1, 0);
    vector<pair<int, pair<int, int>>> lines;

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        lines.push_back({i + 1, {x1, x2}});
    }

    sort(lines.begin(), lines.end(),
         [&](const pair<int, pair<int, int>> &left, const pair<int, pair<int, int>> &right) -> bool
         {
             if (left.second.first == right.second.first)
                 return left.second.second > right.second.second;
             return left.second.first < right.second.first;
         });

    int team = lines[0].first;
    int before = lines[0].second.second;

    for (int i = 1; i < lines.size(); i++)
    {
        if (lines[i].second.first <= before)
        {
            merge(parent, lines[i].first, team);
            before = max(before, lines[i].second.second);
        }
        else
        {
            team = lines[i].first;
            before = lines[i].second.second;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int from, to;
        cin >> from >> to;

        from = findParent(parent, from);
        to = findParent(parent, to);

        if (from == to)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}