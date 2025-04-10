/**
 * @file 19532.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 14:11
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

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // sol 1
    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (a * x + b * y == c && d * x + e * y == f) {
                cout << x << ' ' << y << endl;
                return 0;
            }
        }
    }

    // sol 2
    int y = (f * a - c * d) / (e * a - b * d);
    int x = (c * e - b * f) / (a * e - b * d);
    cout << x << ' ' << y << endl;

    return 0;
}