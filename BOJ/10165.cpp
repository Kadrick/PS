/**
 * @file 10165.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Sweeping
 * @version 0.1
 * @date 2022-09-06 14:44
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

bool comp(const pair<int, pair<int, int>> &left, const pair<int, pair<int, int>> &right)
{
    if (left.second.first == right.second.first)
    {
        return left.second.second > right.second.second;
    }

    return left.second.first < right.second.first;
}

int main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    // idx, start, end
    vector<pair<int, pair<int, int>>> route;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a < b)
        {
            route.push_back({i, {a, b}});
            route.push_back({i, {a + n, b + n}});
        }
        else
        {
            route.push_back({i, {a, b + n}});
        }
    }

    sort(route.begin(), route.end(), comp);

    vector<bool> ans(m, true);
    int start, end;
    start = end = 0;
    for (auto &&section : route)
    {
        int left = section.second.first;
        int right = section.second.second;

        if (!ans[section.first])
            continue;

        if (start <= left && right <= end)
        {
            ans[section.first] = false;
        }
        else
        {
            ans[section.first] = true;
            start = left;
            end = right;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (ans[i])
            cout << i + 1 << ' ';
    }
    cout << endl;

    return 0;
}