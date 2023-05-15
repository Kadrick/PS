/**
 * @file 25588.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2023-05-09
 *
 * @copyright Copyright (c) 2023
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

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1, -1), cache(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int counter = 1;
    vector<int> stair;
    stair.push_back(-1);
    stair.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) != 1)
            counter = 0;
        stair.push_back(++counter);
    }

    cache[0] = 0;
    cache[1] = cache[2] = cache[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        cache[i] = min({cache[i - 1], cache[i - 2], cache[i - 3]}) + 1;
        if (i - k >= 0 && stair[i] >= k)
            cache[i] = min(cache[i], cache[i - k] + 1);
    }

    cout << cache[n] << endl;

    return 0;
}