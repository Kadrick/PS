/**
 * @file d.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16 22:19
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int main(void) {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, pair<long long, long long>>>> graph(n);
    vector<vector<long long>> info(m, vector<long long>(4));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++)
            cin >> info[i][j];

        graph[info[i][0] - 1].push_back(
            {info[i][1] - 1, {info[i][2], info[i][3]}});
        graph[info[i][1] - 1].push_back(
            {info[i][0] - 1, {-info[i][2], -info[i][3]}});
    }

    vector<pair<long long, long long>> visit(n, {LLONG_MAX, LLONG_MAX});
    visit[0] = {0, 0};

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int person_id = q.front();
        q.pop();

        auto cur_pos = visit[person_id];

        for (int i = 0; i < graph[person_id].size(); i++) {
            auto person_near = graph[person_id][i];

            if (visit[person_near.first] != make_pair(LLONG_MAX, LLONG_MAX))
                continue;

            visit[person_near.first] = {
                cur_pos.first + person_near.second.first,
                cur_pos.second + person_near.second.second};
            q.push(person_near.first);
        }
    }

    cout << fixed;
    for (int i = 0; i < n; i++) {
        if (visit[i] != make_pair(LLONG_MAX, LLONG_MAX))
            cout << visit[i].first << ' ' << visit[i].second << endl;
        else
            cout << "undecidable" << endl;
    }

    return 0;
}