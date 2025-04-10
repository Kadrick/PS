/**
 * @file 1167.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 17:35
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int v;
int maxD, maxV;
vector<bool> isVisited;
vector<vector<pair<int, int>>> adj;

void dfs(int node, int dist) {
    if (isVisited[node])
        return;

    if (maxD < dist) {
        maxD = dist;
        maxV = node;
    }

    isVisited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        dfs(adj[node][i].first, dist + adj[node][i].second);
    }
}

int32_t main(int argc, char **argv) {
    fastio;

    cin >> v;
    adj.resize(v + 1, vector<pair<int, int>>());
    isVisited.resize(v + 1, false);
    for (int i = 0; i < v; ++i) {
        int nodeNum;
        cin >> nodeNum;
        while (true) {
            int child;
            cin >> child;
            if (child == -1)
                break;

            int dist;
            cin >> dist;

            adj[nodeNum].push_back(make_pair(child, dist));
        }
    }

    dfs(1, 0);
    maxD = 0;
    isVisited.clear();
    isVisited.resize(v + 1, false);
    dfs(maxV, 0);

    cout << maxD;

    return 0;
}