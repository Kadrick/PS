/**
 * @file 10986.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief prefix sum, math
 * @version 0.1
 * @date 2022-08-19 11:22
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

#define int int64_t

int dp[1000001][3];

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    if (dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int32_t main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    vector<int> sum(n + 1, 0), modulo(m, 0);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }

    for (int i = 1; i <= n; i++)
        modulo[sum[i] % m]++;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (modulo[i] >= 2)
            ans += combination(modulo[i], 2);
    }
    cout << ans + modulo[0] << endl;

    return 0;
}