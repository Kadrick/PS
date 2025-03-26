/**
 * @file 10000.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-26 17:02
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

    int n, ans = 0;
    cin >> n;

    // first : pos, second : open(-1), close(1)
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        int x, r;
        cin >> x >> r;
        arr.push_back({x - r, -1});
        arr.push_back({x + r, 1});
    }

    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };

    sort(arr.begin(), arr.end(), cmp);

    int lastPos = -1;

    // first : pos, state : connect(1), init(0), disconnect(-1)
    vector<pair<int, int>> st;

    for (auto [pos, type] : arr) {

        if (st.empty()) {
            st.push_back({pos, 0});
        } else {
            if (type == -1) { // open
                if (pos == lastPos && st.back().second != -1) {
                    st.back().second = 1;
                } else {
                    st.back().second = -1;
                }
                st.push_back({pos, 0});
            } else if (type == 1) { // close
                ans++;
                if (pos == lastPos && st.back().second == 1) {
                    ans++;
                }
                st.pop_back();
            }
        }

        lastPos = pos;
    }

    cout << ans + 1 << endl;

    return 0;
}