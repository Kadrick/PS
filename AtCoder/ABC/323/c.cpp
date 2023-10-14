/**
 * @file c.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07 21:13
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

    vector<pair<int, int>> point(m);
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        point[i] = {-input, i};
    }

    int upper = 0;
    vector<pair<int, string>> stat;
    for (int i = 0; i < n; i++) {
        string stat_i;
        cin >> stat_i;

        int total = i + 1;
        for (int j = 0; j < m; j++) {
            if (stat_i[j] == 'o')
                total -= point[j].first;
        }

        upper = max(upper, total);
        stat.push_back({total, stat_i});
    }

    sort(point.begin(), point.end());

    for (int i = 0; i < n; i++) {
        int ans = 0, cur = stat[i].first;

        if (upper == cur) {
            cout << ans << endl;
            continue;
        }

        for (int j = 0; j < m; j++) {
            if (stat[i].second[point[j].second] == 'x') {
                cur -= point[j].first;
                ans++;
            }

            if (upper < cur) {
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}