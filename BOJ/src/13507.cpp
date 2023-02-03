/**
 * @file 13507.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief map, prefix sum
 * @version 0.1
 * @date 2023-02-02 16:56
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

    int k;
    string origin, bad;
    cin >> origin >> bad >> k;

    vector<int> sum(origin.size() + 1, 0);
    for (int i = 0; i < origin.size(); i++)
    {
        sum[i + 1] = sum[i];
        if (bad[origin[i] - 'a'] == '0')
            sum[i + 1]++;
    }

    int ans = 0;
    for (int len = 1; len <= origin.size(); len++)
    {
        unordered_map<string, bool> chk;
        string slice;
        int start = 0;

        while (start + len <= origin.size())
        {
            if (sum[start + len] - sum[start] <= k)
            {
                slice = origin.substr(start, len);
                chk[slice] = true;
            }

            start++;
        }

        ans += chk.size();
    }

    cout << ans << endl;

    return 0;
}