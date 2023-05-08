/**
 * @file 25690.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
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

// 0 = white, 1 = black

long long solve(
    vector<vector<int>> &tree,
    vector<vector<long long>> &cost,
    vector<vector<long long>> &cache,
    int root, int here, int color)
{
    if (root != -1 && tree[here].size() == 1)
        return cost[here][color];

    if (cache[here][color])
        return cache[here][color];

    long long ret = cost[here][color];

    for (auto &&child : tree[here])
    {
        if (child == root)
            continue;

        if (color)
            ret += solve(tree, cost, cache, here, child, 0);
        else
            ret += min(
                solve(tree, cost, cache, here, child, 0),
                solve(tree, cost, cache, here, child, 1));
    }

    cache[here][color] = ret;
    return ret;
}

int main(void)
{
    fastio;

    int n;
    cin >> n;

    vector<vector<int>> tree;
    vector<vector<long long>> cost, cache;

    tree.resize(n, vector<int>());
    cost.resize(n, vector<long long>(2, 0));
    cache.resize(n, vector<long long>(2, 0));

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1];

    cout << min(
                solve(tree, cost, cache, -1, 0, 0),
                solve(tree, cost, cache, -1, 0, 1))
         << endl;

    return 0;
}