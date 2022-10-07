/**
 * @file 6068.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-10-07 09:11
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

int main(void)
{
    fastio;

    int n;
    vector<pair<int, int>> pairs;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, s;
        cin >> t >> s;
        pairs.push_back({t, s});
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &left, const pair<int, int> &right) -> bool
         { return left.second > right.second; });

    int startTime = pairs[0].second - pairs[0].first;
    for (int i = 1; i < n; i++)
    {
        if (startTime < pairs[i].second)
            startTime -= pairs[i].first;
        else
            startTime = pairs[i].second - pairs[i].first;
    }

    cout << (startTime < 0 ? -1 : startTime) << endl;
    return 0;
}