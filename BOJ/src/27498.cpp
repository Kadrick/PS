/**
 * @file 27498.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

vector<int> Team;

int findTeam(int target)
{
    if (Team[target] == 0)
        return target;
    return Team[target] = findTeam(Team[target]);
};

bool mergeTeam(int u, int v)
{
    u = findTeam(u);
    v = findTeam(v);

    if (u != v)
    {
        Team[max(u, v)] = min(u, v);
        return true;
    }
    return false;
};

int main(void)
{
    fastio;

    int n, m, ans = 0;
    cin >> n >> m;

    Team.resize(n + 1, 0);
    vector<pair<pair<int, int>, pair<int, int>>> edges(m);

    auto sortEdge = [](
                        pair<pair<int, int>, pair<int, int>> &left,
                        pair<pair<int, int>, pair<int, int>> &right) -> bool
    {
        if (left.first.first == right.first.first)
        {
            return left.first.second > right.first.second;
        }
        return left.first.first > right.first.first;
    };

    for (int i = 0; i < m; i++)
    {
        cin >>
            edges[i].second.first >>
            edges[i].second.second >>
            edges[i].first.second >>
            edges[i].first.first;
    }

    sort(edges.begin(), edges.end(), sortEdge);

    for (auto &&edge : edges)
    {
        if (edge.first.first == 1)
            mergeTeam(edge.second.first, edge.second.second);
        else if (!mergeTeam(edge.second.first, edge.second.second))
            ans += edge.first.second;
    }
    cout << ans << endl;

    return 0;
}