/**
 * @file 14938.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-12-09 09:34
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

int getItem(vector<vector<pair<int, int>>> &graph, vector<int> &items, int start, int &scope)
{
    vector<int> dist(graph.size(), INT32_MAX / 2);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto here = pq.top();
        pq.pop();

        for (auto &&next : graph[here.second])
        {
            if (next.second - here.first < dist[next.first])
            {
                dist[next.first] = next.second - here.first;
                pq.push({-dist[next.first], next.first});
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (i + 1 == start)
            continue;
        sum += dist[i + 1] <= scope ? items[i + 1] : 0;
    }

    return sum + items[start];
}

int main(void)
{
    fastio;

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> item(n + 1);
    for (int i = 0; i < n; i++)
        cin >> item[i + 1];

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, getItem(graph, item, i + 1, m));

    cout << ans << endl;

    return 0;
}