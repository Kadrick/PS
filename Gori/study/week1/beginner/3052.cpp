/**
 * @file 3052.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-26 16:55
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

    vector<int> cnt(42, 0);
    for (int i = 0; i < 10; ++i) {
        int a;
        cin >> a;
        cnt[a % 42]++;
    }

    int ans = 0;
    for (int i = 0; i < 42; ++i)
        if (cnt[i] > 0)
            ans++;

    cout << ans << endl;

    return 0;
}