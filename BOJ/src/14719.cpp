/**
 * @file 14719.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Brute force
 * @version 0.1
 * @date 2022-10-11 15:47
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

    int h, w;
    cin >> h >> w;
    vector<int> heightMap;
    for (int i = 0; i < w; i++)
    {
        int height;
        cin >> height;
        heightMap.push_back(height);
    }

    int ans = 0;
    for (int i = 1; i < w - 1; i++)
    {
        int left, right;
        left = right = heightMap[i];

        for (int j = i - 1; j >= 0; j--)
            left = max(left, heightMap[j]);

        for (int j = i + 1; j < w; j++)
            right = max(right, heightMap[j]);

        ans += max(0, min(left, right) - heightMap[i]);
    }
    cout << ans << endl;

    return 0;
}