/**
 * @file 10164.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-09-08 09:11
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

#define int long long
#define Point pair<int, int>
#define row first
#define col second

int findCases(Point start, Point end)
{
    int rightMove = end.col - start.col;
    int downMove = end.row - start.row;
    int sum = rightMove + downMove;

    int numerator = 1;
    for (int i = sum - min(rightMove, downMove) + 1; i <= sum; i++)
        numerator *= i;

    int denominator = 1;
    for (int i = 1; i <= min(rightMove, downMove); i++)
        denominator *= i;

    return (numerator / denominator);
}

int32_t main(void)
{
    fastio;

    int n, m, k;
    cin >> n >> m >> k;
    k--;

    vector<int> cases;
    vector<Point> spots;

    spots.push_back({0, 0});
    if (k != -1)
        spots.push_back({k / m, k % m});
    spots.push_back({n - 1, m - 1});

    for (int i = 0; i < spots.size() - 1; i++)
        cases.push_back(findCases(spots[i], spots[i + 1]));

    int ans = 1;

    for (int i = 0; i < cases.size(); i++)
        ans *= cases[i];

    cout << ans << endl;

    return 0;
}