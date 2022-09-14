/**
 * @file 2126.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST
 * @version 0.1
 * @date 2022-09-07 14:11
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

#define int long long

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

bool checkResource(int bridge, int &balance, vector<pair<pair<int, int>, pair<int, int>>> &edges, double value)
{
    vector<int> parent(bridge + 1, 0);
    for (int i = 0; i < bridge + 1; i++)
        parent[i] = i;

    sort(
        edges.begin(), edges.end(),
        [&](
            const pair<pair<int, int>, pair<int, int>> &left,
            const pair<pair<int, int>, pair<int, int>> &right)
        {
            return left.first.first + value * left.first.second <
                   right.first.first + value * right.first.second;
        });

    pair<int, int> total = {0, 0};
    for (auto &&edge : edges)
    {
        int cost = edge.first.first;
        int time = edge.first.second;
        int from = edge.second.first;
        int to = edge.second.second;

        if (merge(parent, from, to))
        {
            total.first += cost;
            total.second += time;
        }
    }

    return balance > total.first + value * total.second;
}

int32_t main(void)
{
    fastio;

    int n, m, f;
    cin >> n >> m >> f;

    vector<pair<pair<int, int>, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, cost, time;
        cin >> u >> v >> cost >> time;
        edges.push_back({{cost, time}, {u, v}});
    }

    double benefitMax = ((double)f - (n - 1)) / (n - 1);
    double benefitMin = 0;

    double ans = -1;
    for (int i = 0; i < 100; i++) // 2^100 = ?
    {
        double center = (benefitMax + benefitMin) / 2;
        if (checkResource(n, f, edges, center))
        {
            ans = center;
            benefitMin = center;
        }
        else
            benefitMax = center;
    }

    cout << fixed;
    cout.precision(4);

    cout << (ans > 0 ? ans : 0.0000) << endl;

    return 0;
}