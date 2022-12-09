/**
 * @file 17299.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief stack
 * @version 0.1
 * @date 2022-12-09 16:18
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
    vector<int> arr(n);
    vector<int> cnt(1000001, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    stack<pair<int, int>> st;
    st.push({cnt[arr.back()], arr.back()});
    vector<int> ans(n, -1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (cnt[arr[i]] < st.top().first)
        {
            ans[i] = st.top().second;
            st.push({cnt[arr[i]], arr[i]});
        }
        else if (cnt[arr[i]] >= st.top().first)
        {
            while (!st.empty() && cnt[arr[i]] >= st.top().first)
                st.pop();

            if (!st.empty())
                ans[i] = st.top().second;
            st.push({cnt[arr[i]], arr[i]});
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}