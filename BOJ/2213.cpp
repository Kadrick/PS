/**
 * @file 2213.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-09-13 14:09
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

vector<int> point;
vector<vector<int>> tree;
vector<vector<int>> dp;

int solve(int current, int parent, bool isAdd)
{
    int &ret = dp[current][isAdd];
    if (ret != -1)
        return ret;

    ret = 0;
    if (isAdd)
    {
        ret += point[current];

        for (auto &&child : tree[current])
        {
            if (child == parent)
                continue;
            ret += solve(child, current, false);
        }
    }
    else
    {
        for (auto &&child : tree[current])
        {
            if (child == parent)
                continue;
            ret += max(solve(child, current, true), solve(child, current, false));
        }
    }

    return ret;
}

void trace(vector<int> &path, int current, int parent, bool isAdd)
{
    if (isAdd)
    {
        path.push_back(current);
        for (auto &&child : tree[current])
        {
            if (child == parent)
                continue;
            trace(path, child, current, false);
        }
    }
    else
    {
        for (auto &&child : tree[current])
        {
            if (child == parent)
                continue;

            if (dp[child][false] < dp[child][true])
                trace(path, child, current, true);
            else
                trace(path, child, current, false);
        }
    }
}

int main(void)
{
    fastio;

    int n;
    cin >> n;

    tree.resize(n + 1, vector<int>());
    dp.resize(n + 1, vector<int>(2, -1));
    point.resize(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        point[i + 1] = tmp;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }

    int rootContain = solve(1, 0, true);
    int rootNotContain = solve(1, 0, false);

    int ans = max(rootContain, rootNotContain);
    cout << ans << endl;

    vector<int> path;
    if (rootContain > rootNotContain)
        trace(path, 1, 0, true);
    else
        trace(path, 1, 0, false);

    sort(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << ' ';
    cout << endl;

    return 0;
}