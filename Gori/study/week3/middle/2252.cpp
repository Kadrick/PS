/**
 * @file 2252.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 17:38
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int n, m;
vector<int> inDegree;
vector<vector<int>> g;

void topological() {
    queue<int> q;
    // 진입 차수가 0이면 큐에 넣기
    for (int i = 1; i <= n; ++i) {
        if (!inDegree[i])
            q.push(i);
    }

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        cout << here << ' ';
        // 그래프 갱신
        for (int i = 0; i < g[here].size(); ++i) {
            inDegree[g[here][i]]--;
            if (!inDegree[g[here][i]])
                q.push(g[here][i]);
        }
    }
}

int32_t main(int argc, char **argv) {
    fastio;

    cin >> n >> m;
    inDegree.resize(n + 1, 0);
    g.resize(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        inDegree[v]++;
    }

    topological();

    return 0;
}