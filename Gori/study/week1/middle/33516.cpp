/**
 * @file 33516.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-26 16:59
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

const string skeep = "skeep";

int countSkeep(vector<char> &st) {

    int ret = 0;

    while (st.size() >= 5) {
        bool check = true;
        int last = st.size() - 1;

        for (int i = 0; i < 5; ++i) {
            if (i == 4) {
                check = st[last - i] == 's';
                break;
            }

            if (st[last - i] == '*') {
                continue;
            }

            if (st[last - i] == skeep[4 - i]) {
                continue;
            } else {
                check = false;
                break;
            }
        }

        if (check) {
            ret++;

            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.push_back('*');
        } else {
            break;
        }
    }

    return ret;
}

int32_t main(int argc, char **argv) {
    fastio;

    int n;
    string s;
    cin >> n >> s;

    vector<char> st(0);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        st.push_back(s[i]);
        ans += countSkeep(st);
    }

    cout << ans << endl;

    return 0;
}