/**
 * @file 10844.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 14:59
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

int MOD = 1'000'000'000;

int32_t main(int argc, char **argv) {
    fastio;

    int N;
    cin >> N;

    // dp[a][b] : a로 끝나는 b자리 수의 개수
    vector<vector<int>> dp(10, vector<int>(100, 0));

    for (int i = 1; i <= 9; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[j][i] = dp[j + 1][i - 1] % MOD;
            } else if (j == 9) {
                dp[j][i] = dp[j - 1][i - 1] % MOD;
            } else {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[i][N]) % MOD;
    }

    cout << ans << endl;
    return 0;
}