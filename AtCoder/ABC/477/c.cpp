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

    string s, t;
    int q;

    cin >> q >> s >> t;

    int start = 0;
    vector<int> start_pos;
    vector<int> end_pos;
    while (true)
    {
        auto result = s.find(t, start);

        if (result == string::npos)
        {
            break;
        }

        start = result + 1;

        start_pos.push_back(result + 1);
        end_pos.push_back(result + 1 + t.size() - 1);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int find = lower_bound(start_pos.begin(), start_pos.end(), l) - start_pos.begin();
        if (find != start_pos.size() && end_pos[find] <= r)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}