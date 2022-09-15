/**
 * @file 20168.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra + parametric search
 * @version 0.1
 * @date 2022-09-15 09:18
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

const int inf = 1e15;

int n, m, a, b, c;
vector<int> costs;
vector<vector<pair<int, int>>> graph(100001, vector<pair<int, int>>());

bool pass(int fence)
{
    vector<int> dist(graph.size() + 1, inf);
    dist[a] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, a});

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        int money = -current.first;
        int here = current.second;

        for (auto &&next : graph[here])
        {
            if (next.second > fence)
                continue;

            if (money + next.second < dist[next.first])
            {
                dist[next.first] = money + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }

    return (dist[b] <= c ? true : false);
}

int32_t main(void)
{
    fastio;

    cin >> n >> m >> a >> b >> c;

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
        costs.push_back(cost);
    }

    sort(costs.begin(), costs.end());
    costs.erase(unique(costs.begin(), costs.end()), costs.end());

    int bottom = 0,
        top = costs.size() - 1, ans = -1;

    while (bottom <= top)
    {
        int middle = (bottom + top) >> 1;
        if (pass(costs[middle]))
        {
            top = middle - 1;
            ans = costs[middle];
        }
        else
            bottom = middle + 1;
    }

    cout << ans << endl;

    return 0;
}