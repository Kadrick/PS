/**
 * @file 1007.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Brute force
 * @version 0.1
 * @date 2022-10-11 13:49
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

int32_t main(void)
{
    fastio;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> points;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        vector<int> included(n / 2, 0);
        for (int i = 0; i < n / 2; i++)
            included.push_back(1);

        double ans = DBL_MAX;
        do
        {
            pair<int, int> sum = {0, 0};
            for (int i = 0; i < n; i++)
            {
                if (included[i] == 1)
                {
                    sum.first += points[i].first;
                    sum.second += points[i].second;
                }
                else
                {
                    sum.first -= points[i].first;
                    sum.second -= points[i].second;
                }
            }
            ans = min(ans, sqrt(sum.first * sum.first + sum.second * sum.second));
        } while (next_permutation(included.begin(), included.end()));
        cout << fixed;
        cout.precision(10);
        cout << ans << endl;
    }

    return 0;
}