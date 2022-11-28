/**
 * @file 17498.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-11-28 10:10
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

int N, M, D;

int solve(int r, int c, vector<vector<int>> &dp, vector<vector<int>> &num)
{
    if (r == 0)
        return 0;

    if (dp[r][c] != INT_MIN)
        return dp[r][c];

    for (int delta = 1; delta <= D; delta++)
    {
        for (int dy = 1; dy <= delta; dy++)
        {
            int scope = delta - dy;

            if (r - dy < 0)
                break;

            int y = r - dy;

            for (int dx = -scope; dx <= scope; dx++)
            {
                int x = c + dx;

                if (x < 0 || x >= M)
                    continue;

                dp[r][c] = max(dp[r][c], solve(y, x, dp, num) + num[y][x] * num[r][c]);
            }
        }
    }

    return dp[r][c];
}

int main(void)
{
    fastio;
    cin >> N >> M >> D;

    vector<vector<int>> dp(N, vector<int>(M, INT_MIN));
    vector<vector<int>> num(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> num[i][j];
    }

    int ans = INT_MIN;
    for (int i = 0; i < M; i++)
        ans = max(ans, solve(N - 1, i, dp, num));
    cout << ans << endl;

    return 0;
}