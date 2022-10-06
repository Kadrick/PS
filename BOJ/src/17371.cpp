/**
 * @file 17371.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Geometry
 * @version 0.1
 * @date 2022-10-06 16:38
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

double calc(const pair<int, int> &start, const pair<int, int> &end)
{
    return sqrt(pow(start.first - end.first, 2) + pow(start.second - end.second, 2));
}

int32_t main(void)
{
    fastio;

    int n;
    vector<pair<int, int>> points;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    double ans = -1, minimum = DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        double maximum = -1;
        for (int j = 0; j < n; j++)
        {
            double dist = calc(points[i], points[j]);
            maximum = max(maximum, dist);
        }

        if (maximum < minimum)
        {
            minimum = maximum;
            ans = i;
        }
    }

    cout << points[ans].first << ' ' << points[ans].second << endl;

    return 0;
}