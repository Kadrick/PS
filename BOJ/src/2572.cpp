/**
 * @file 2572.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-10-13 15:02
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

int solve(vector<vector<int>> &dp,
          vector<vector<pair<int, char>>> &graph,
          vector<char> &card,
          int idx, int city)
{
    if (idx == card.size())
        return 0;

    int &ret = dp[idx][city];
    if (ret != -1)
        return ret;

    ret = 0;

    for (auto &&next : graph[city])
    {
        int nextCity = next.first;
        char color = next.second;

        int bonus = color == card[idx] ? 10 : 0;

        ret = max(ret, solve(dp, graph, card, idx + 1, nextCity) + bonus);
    }

    return ret;
}

int main(void)
{
    fastio;

    int n;
    cin >> n;
    vector<char> card(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> card[i + 1];

    int m, k;
    cin >> m >> k;

    vector<vector<pair<int, char>>> graph(m + 1);
    for (int i = 0; i < k; i++)
    {
        int from, to;
        char color;
        cin >> from >> to >> color;
        graph[from].push_back({to, color});
        graph[to].push_back({from, color});
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve(dp, graph, card, 1, 1) << endl;

    return 0;
}