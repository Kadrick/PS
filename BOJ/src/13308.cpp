/**
 * @file 13308.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-10-11 14:24
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

int32_t main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    vector<int> oil(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> oil[i + 1];

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    int ans = 0;
    vector<vector<bool>> visit(2510, vector<bool>(2510, false));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {1, oil[1]}});

    while (!pq.empty())
    {
        int total = -pq.top().first;
        int cur = pq.top().second.first;
        int minOil = pq.top().second.second;
        pq.pop();

        if (cur == n)
        {
            ans = total;
            break;
        }

        if (visit[cur][minOil])
            continue;
        visit[cur][minOil] = true;

        for (auto &&next : graph[cur])
        {
            int pos = next.first;
            int dist = next.second;
            int cost = dist * minOil;
            int updateOil = min(minOil, oil[pos]);
            pq.push({-(total + cost), {pos, updateOil}});
        }
    }

    cout << ans << endl;

    return 0;
}