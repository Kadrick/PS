/**
 * @file 16287.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief meet in the middle
 * @version 0.1
 * @date 2022-10-26 13:05
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

    int w, n;
    cin >> w >> n;

    vector<int> arr(n);
    vector<pair<int, int>> possible(400001, {-1, -1});
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (possible[arr[i] + arr[j]].first == -1)
            {
                possible[arr[i] + arr[j]].first = i;
                possible[arr[i] + arr[j]].second = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target = w - arr[i] - arr[j];
            if (target < 0 || target > 400000 || possible[target].first == -1)
                continue;

            if (
                possible[target].first != i &&
                possible[target].second != j &&
                possible[target].first != j &&
                possible[target].second != i)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}