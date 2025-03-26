/**
 * @file 13146.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-03-24 15:06
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

    int n;
    cin >> n;

    long long ans = 0, maxVal = 0;
    vector<long long> st;

    for (int i = 0; i < n; ++i) {
        long long input;
        cin >> input;

        if (!st.empty() && st.back() < input) {
            ans += input - st.back();
            while (!st.empty() && st.back() < input)
                st.pop_back();
        }

        st.push_back(input);
    }

    cout << ans + st.front() - st.back() << endl;

    return 0;
}