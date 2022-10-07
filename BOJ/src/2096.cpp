/**
 * @file 2096.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-10-07 14:31
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
    cin >> n;
    int src[3];
    vector<pair<int, int>> tmp(3, {0, 0});
    vector<pair<int, int>> save(3, {0, 0});
    auto fitPos = [](int x, int y) -> int
    {
        return min(max(x + y, 0), 2);
    };

    for (int i = 0; i < n; i++)
    {
        tmp = save;
        for (int j = 0; j < 3; j++)
            save[j] = {0, 1e9};

        cin >> src[0] >> src[1] >> src[2];
        for (int j = 0; j < 3; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                int pos = fitPos(j, k);
                save[pos].first = max(save[pos].first, tmp[j].first + src[pos]);
                save[pos].second = min(save[pos].second, tmp[j].second + src[pos]);
            }
        }
    }

    cout << max({save[0].first, save[1].first, save[2].first}) << " "
         << min({save[0].second, save[1].second, save[2].second}) << endl;

    return 0;
}