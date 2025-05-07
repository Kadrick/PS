/**
 * @file 1620.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 14:51
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                                                         \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    int N, M;
    cin >> N >> M;

    vector<string> v(N);
    unordered_map<string, int> um;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        um[v[i]] = i + 1;
    }

    string query;
    for (int i = 0; i < M; i++) {
        cin >> query;

        if ('0' <= query[0] && query[0] <= '9') {
            cout << v[stoi(query) - 1] << endl;
        } else {
            cout << um[query] << endl;
        }
    }

    return 0;
}