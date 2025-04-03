/**
 * @file 4485.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 14:05
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int round = 0;
    while (true) {
        int n;
        cin >> n;

        if (!n)
            break;

        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
        }

        dist[0][0] = graph[0][0];
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-graph[0][0], {0, 0}});

        while (!pq.empty()) {
            int d = -pq.top().first;
            pair<int, int> pos = pq.top().second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int mx = pos.first + dx[i];
                int my = pos.second + dy[i];

                if (0 <= mx && mx < n && 0 <= my && my < n) {
                    int cost = d + graph[mx][my];
                    if (dist[mx][my] > cost) {
                        dist[mx][my] = cost;
                        pq.push({-cost, {mx, my}});
                    }
                }
            }
        }

        cout << "Problem " << ++round << ": " << dist[n - 1][n - 1] << endl;
    }

    return 0;
}