/**
 * @file 1157.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 13:00
 * @copyright Copyright (c) 2025
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

    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - (c >= 'a' ? 'a' : 'A')]++;
    }

    char ans = '?';
    int max_cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
            ans = i + 'A';
        } else if (cnt[i] == max_cnt) {
            ans = '?';
        }
    }

    cout << ans << endl;

    return 0;
}
