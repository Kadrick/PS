/**
 * @file 10809.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-26 16:58
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    string s;
    cin >> s;

    vector<int> ans(26, -1);
    for (int i = 0; i < s.length(); ++i) {
        if (ans[s[i] - 'a'] == -1)
            ans[s[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; ++i)
        cout << ans[i] << ' ';

    return 0;
}