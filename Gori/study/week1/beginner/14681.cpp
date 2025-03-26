/**
 * @file 14681.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-26 16:50
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0)
        cout << 1 << endl;
    else if (x < 0 && y > 0)
        cout << 2 << endl;
    else if (x < 0 && y < 0)
        cout << 3 << endl;
    else
        cout << 4 << endl;

    return 0;
}