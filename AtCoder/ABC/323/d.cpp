/**
 * @file d.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07 21:45
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

    map<long long, long long> m;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long s, c;
        cin >> s >> c;
        m[s] = c;
    }

    long long total = 0;

    for (auto it = m.begin(); it != m.end(); it++) {

        long long size = it->first;
        long long cnt = it->second;

        total += cnt % 2;

        cnt /= 2;
        size *= 2;

        while (cnt > 1) {
            if (cnt % 2) {
                m[size] = m[size] + 1;
                cnt /= 2;
                size *= 2;
            } else {
                cnt /= 2;
                size *= 2;
            }
        }

        m[size] = m[size] + cnt;
    }

    cout << total << endl;

    return 0;
}