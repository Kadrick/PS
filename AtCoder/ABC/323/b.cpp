/**
 * @file b.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07 20:58
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

    int n;
    cin >> n;

    vector<pair<int, int>> cnt;

    for (int i = 0; i < n; i++) {

        string result;
        cin >> result;

        int wins = 0;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (result[j] == 'o')
                wins++;
        }

        cnt.push_back({wins, i});
    }

    auto cmp = [](const pair<int, int> &left,
                  const pair<int, int> &right) -> bool {
        if (left.first == right.first) {
            return left.second < right.second;
        }
        return left.first > right.first;
    };

    sort(cnt.begin(), cnt.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << cnt[i].second + 1 << ' ';
    }
    cout << endl;

    return 0;
}