/**
 * @file 1010.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 15:47
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int dp[30][30];

int comb(int n, int r) {
    if (!dp[n][r]) {
        if (n == r || r == 0)
            dp[n][r] = 1;
        else
            dp[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
    }
    return dp[n][r];
}

int32_t main(void) {
    fastio;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        cout << comb(m, n) << endl;
    }

    return 0;
}