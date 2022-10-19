/**
 * @file 1022.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-10-19 14:01
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

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int num = 1;
    int maxLen = 0;

    r1 += 5000;
    r2 += 5000;
    c1 += 5000;
    c2 += 5000;

    auto inRange = [&](int &y, int &x) -> bool
    {
        return r1 <= y && y <= r2 && c1 <= x && x <= c2;
    };

    vector<vector<string>> ans(r2 - r1 + 1, vector<string>(c2 - c1 + 1, ""));

    pair<int, int> stamp = {5000, 5000};

    if (inRange(stamp.first, stamp.second))
    {
        string tmp = to_string(num);
        maxLen = max(int(tmp.size()), maxLen);
        ans[stamp.first - r1][stamp.second - c1] = tmp;
    }

    for (int i = 0; i < 5000; i++)
    {
        int size = 2 * (i + 1) + 1;

        stamp.second += 1;
        ++num;
        if (inRange(stamp.first, stamp.second))
        {
            string tmp = to_string(num);
            maxLen = max(int(tmp.size()), maxLen);
            ans[stamp.first - r1][stamp.second - c1] = tmp;
        }

        // up
        for (int j = 0; j < size - 2; j++)
        {
            --stamp.first;
            ++num;

            if (inRange(stamp.first, stamp.second))
            {
                string tmp = to_string(num);
                maxLen = max(int(tmp.size()), maxLen);
                ans[stamp.first - r1][stamp.second - c1] = tmp;
            }
        }
        // left
        for (int j = 0; j < size - 1; j++)
        {
            --stamp.second;
            ++num;

            if (inRange(stamp.first, stamp.second))
            {
                string tmp = to_string(num);
                maxLen = max(int(tmp.size()), maxLen);
                ans[stamp.first - r1][stamp.second - c1] = tmp;
            }
        }

        // down
        for (int j = 0; j < size - 1; j++)
        {

            ++stamp.first;
            ++num;

            if (inRange(stamp.first, stamp.second))
            {
                string tmp = to_string(num);
                maxLen = max(int(tmp.size()), maxLen);
                ans[stamp.first - r1][stamp.second - c1] = tmp;
            }
        }

        // right
        for (int j = 0; j < size - 1; j++)
        {
            ++stamp.second;
            ++num;

            if (inRange(stamp.first, stamp.second))
            {
                string tmp = to_string(num);
                maxLen = max(int(tmp.size()), maxLen);
                ans[stamp.first - r1][stamp.second - c1] = tmp;
            }
        }
    }

    for (int i = 0; i <= r2 - r1; i++)
    {
        for (int j = 0; j <= c2 - c1; j++)
        {
            string target = ans[i][j];
            int paddingLen = maxLen - target.size();

            if (paddingLen)
                target = string(paddingLen, ' ') + target;

            cout << target << ' ';
        }
        cout << endl;
    }

    return 0;
}