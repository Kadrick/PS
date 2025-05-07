/**
 * @file 16139.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 15:31
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                                                         \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    string s;
    int q;

    cin >> s >> q;

    vector<vector<int>> v(26, vector<int>(s.size() + 1, 0));

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            v[j][i + 1] = v[j][i];
        }
        v[s[i] - 'a'][i + 1]++;
    }

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << v[c - 'a'][r + 1] - v[c - 'a'][l] << endl;
    }

    return 0;
}