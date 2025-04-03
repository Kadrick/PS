/**
 * @file 24263.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 13:25
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

    int n;
    cin >> n;
    cout << n << endl << 1;

    for (int i = 0; i < n; i++) {
        cout << tmp << ' ';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << ' ' << j << endl;
        }
    }

    for (int i = 0; i < pow(2, n); i++) {
        cout << i << endl;
    }

    return 0;
}