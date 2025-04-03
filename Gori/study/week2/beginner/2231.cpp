/**
 * @file 2231.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 13:27
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

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long sum = i;
        long long tmp = i;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}