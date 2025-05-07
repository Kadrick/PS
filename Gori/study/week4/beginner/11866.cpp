/**
 * @file 11866.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 14:44
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

    int N, K;
    cin >> N >> K;

    vector<int> v(N), ans;
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }

    int idx = 0;
    while (ans.size() < N) {
        idx = (idx + K - 1) % v.size();
        ans.push_back(v[idx]);
        v.erase(v.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? ">" : ", ");
    }

    return 0;
}