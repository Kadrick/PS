/**
 * @file 12888.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-11-28 11:05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

long long dp[61];

int main(void)
{
    fastio;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= 60; i++)
    {
        if (i % 2)
            dp[i] = dp[i - 1] * 2 - 1;
        else
            dp[i] = dp[i - 1] * 2 + 1;
    }

    int target;
    cin >> target;
    cout << dp[target] << endl;

    return 0;
}