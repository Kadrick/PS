/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
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

    int n, q;
    cin >> n >> q;

    vector<bool> is_open(n, true);
    vector<vector<int>> tile(n, vector<int>());
    vector<int> color_idx;
    vector<char> color_ch;

    color_idx.push_back(0);
    color_ch.push_back('a');

    for (int i = 1; i <= q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int pos;
            cin >> pos;
            pos--;
            is_open[pos] = !is_open[pos];
            tile[pos].push_back(i);
        }
        else if (type == 2)
        {
            char c;
            cin >> c;
            color_idx.push_back(i);
            color_ch.push_back(c);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_open[i])
        {
            // open
            if (tile[i].empty() || tile[i].back() < color_idx.back())
            {
                cout << color_ch.back();
                continue;
            }
            tile[i].pop_back();
        }

        // close
        for (int j = tile[i].size() - 1; j >= 0; j -= 2)
        {
            int close_qidx = tile[i][j];
            int open_qidx = j == 0 ? -1 : tile[i][j - 1];
            if (close_qidx - open_qidx == 1)
            {
                continue;
            }

            int close = upper_bound(color_idx.begin(), color_idx.end(), close_qidx) - color_idx.begin();
            if (close > 0)
            {
                if (color_idx[close - 1] > open_qidx)
                {
                    cout << color_ch[close - 1];
                    break;
                }
            }
        }
    }

    return 0;
}