/**
 * @file 10165.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-08 10:55
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

    int n, m;
    cin >> n >> m;

    // <<start, end>, index>
    vector<pair<pair<int, int>, int>> lines;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if (s < e) {
            lines.push_back({{s, e}, i});
            lines.push_back({{s + n, e + n}, i});
        } else {
            lines.push_back({{s, e + n}, i});
        }
    }

    auto cmp = [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        }
        return a.first.first < b.first.first;
    };

    sort(lines.begin(), lines.end(), cmp);

    /*========================================================================*/

    vector<bool> ans(m, true);
    auto selected_line = lines[0];

    auto inRange = [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
        return a.first.first <= b.first.first && b.first.second <= a.first.second;
    };

    for (int i = 1; i < lines.size(); i++) {
        if (!ans[lines[i].second]) {
            continue;
        }

        if (inRange(selected_line, lines[i])) {
            ans[lines[i].second] = false;
        } else {
            selected_line = lines[i];
        }
    }

    /*========================================================================*/

    for (int i = 0; i < m; i++) {
        if (ans[i]) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}