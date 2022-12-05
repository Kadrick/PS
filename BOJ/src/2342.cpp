/**
 * @file 2342.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-12-05 13:48
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

int power[5][5] = {
    {0, 2, 2, 2, 2},
    {2, 1, 3, 4, 3},
    {2, 3, 1, 3, 4},
    {2, 4, 3, 1, 3},
    {2, 3, 4, 3, 1}};

vector<int> pattern;

int dp[100001][5][5];

int solve(int step, int left, int right)
{
    if (step == pattern.size())
        return 0;

    int &ret = dp[step][left][right];
    if (ret != -1)
        return ret;

    ret = 0;
    int next = pattern[step];

    ret = min(
        power[left][next] + solve(step + 1, next, right),
        power[right][next] + solve(step + 1, left, next));

    return ret;
}

int main(void)
{
    fastio;

    int input = 0;
    memset(dp, -1, sizeof(dp));
    while (true)
    {
        cin >> input;
        if (!input)
            break;
        pattern.push_back(input);
    }

    cout << solve(0, 0, 0) << endl;

    return 0;
}