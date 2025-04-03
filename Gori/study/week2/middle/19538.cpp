/**
 * @file 19538.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 13:51
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

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> ans(N + 1, -1);

    for (int i = 0; i < N; i++) {
        while (true) {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
                break;
            graph[i + 1].push_back(tmp);
        }
    }

    queue<int> rumor;

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        ans[tmp] = 0;
        rumor.push(tmp);
    }

    while (!rumor.empty()) {
        int creator = rumor.front();
        rumor.pop();

        for (auto &&i : graph[creator]) {
            if (ans[i] == -1) {
                int cnt = 0;
                for (auto &&neighbor : graph[i]) {
                    if (ans[neighbor] != -1 && ans[neighbor] <= ans[creator])
                        cnt++;
                }

                int half = graph[i].size() / 2;
                if (graph[i].size() % 2 == 1)
                    half += 1;

                if (cnt >= half) {
                    ans[i] = ans[creator] + 1;
                    rumor.push(i);
                }
            }
        }
    }

    for (int i = 1; i < N + 1; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}