/**
 * @file 1238.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-12-08 14:25
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

const int INF = INT_MAX;

vector<int> dijkstraOneToAll(vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> dist(graph.size() + 1, INF / 2);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto here = pq.top();
        pq.pop();

        for (auto &&next : graph[here.second])
        {
            if (-here.first + next.second < dist[next.first])
            {
                dist[next.first] = -here.first + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }

    return dist;
}

int dijkstraOneToOne(vector<vector<pair<int, int>>> &graph, int start, int end)
{
    vector<int> dist(graph.size() + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto here = pq.top();
        pq.pop();

        for (auto &&next : graph[here.second])
        {
            if (-here.first + next.second < dist[next.first])
            {
                dist[next.first] = -here.first + next.second;
                pq.push({-dist[next.first], next.first});
            }
        }
    }

    return dist[end];
}

int main(void)
{
    fastio;

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>>
        graph(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int ans = 0;
    vector<int> returning = dijkstraOneToAll(graph, x);

    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        ans = max(ans, returning[i] + dijkstraOneToOne(graph, i, x));
    }

    cout << ans << endl;

    return 0;
}