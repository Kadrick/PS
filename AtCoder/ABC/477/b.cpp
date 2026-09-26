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

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> arr(n, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;
        arr[i] = {pos, i + 1};
    }

    sort(arr.begin(), arr.end());

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            if (arr[i + 1].first - arr[i].first < d)
            {
                continue;
            }
        }

        if (i >= 1)
        {
            if (arr[i].first - arr[i - 1].first < d)
            {
                continue;
            }
        }

        ans.push_back(arr[i].second);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}