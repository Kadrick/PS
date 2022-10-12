/**
 * @file 2467.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief two pointer
 * @version 0.1
 * @date 2022-10-12 09:10
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

bool candidate(int origin, int newest)
{
    return abs(newest) < abs(origin);
}

int main(void)
{
    fastio;
    int n;
    cin >> n;

    vector<int> liquid;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        liquid.push_back(tmp);
    }

    sort(liquid.begin(), liquid.end());

    int start = 0, end = liquid.size() - 1;

    pair<int, pair<int, int>> ans = {INT32_MAX, {0, 0}};

    while (start < end)
    {
        int sum = liquid[start] + liquid[end];

        if (candidate(ans.first, sum))
        {
            ans.first = sum;
            ans.second.first = liquid[start];
            ans.second.second = liquid[end];
        }

        if (sum < 0)
            start++;
        else if (sum > 0)
            end--;
        else
            break;
    }

    cout << ans.second.first << ' ' << ans.second.second << endl;

    return 0;
}