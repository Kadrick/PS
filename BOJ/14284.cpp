/**
 * @file 14284.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-09-06 09:59
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

const int INF = 1e9;

int dijkstra(int start, int end, int N, const vector<vector<pair<int, int>>> graph)
{
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[curNode].size(); i++)
        {
            int nxtNode = graph[curNode][i].first;
            int nxtDist = curDist + graph[curNode][i].second;

            if (nxtDist < dist[nxtNode])
            {
                dist[nxtNode] = nxtDist;
                pq.push({-nxtDist, nxtNode});
            }
        }
    }

    return dist[end];
}

int main(void)
{
    fastio;

    int n, m, s, t;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    cin >> s >> t;

    cout << dijkstra(s, t, n, graph) << endl;

    return 0;
}