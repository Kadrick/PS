/**
 * @file 14699.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-10-13 16:00
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

int solve(vector<int> &dp, vector<vector<int>> &graph, int idx)
{
    if (idx >= dp.size())
        return 0;

    int &ret = dp[idx];
    if (ret != -1)
        return ret;

    ret = 1;

    for (auto &&next : graph[idx])
        ret = max(ret, solve(dp, graph, next) + 1);

    return ret;
}

int main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> height(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i + 1];
        graph[0].push_back(i + 1);
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (height[u] < height[v])
            graph[u].push_back(v);
        else if (height[u] > height[v])
            graph[v].push_back(u);
    }

    vector<int> dp(n + 1, -1);

    solve(dp, graph, 0);

    for (int i = 0; i < n; i++)
        cout << dp[i + 1] << endl;
    cout << endl;

    return 0;
}