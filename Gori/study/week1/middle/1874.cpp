/**
 * @file 1874.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief stack
 * @version 0.1
 * @date 2025-03-24 13:40
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

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    stack<int> st;
    vector<char> ans;

    int val = 1;
    for (int i = 0; i < n; ++i) {
        // push
        while (val <= v[i]) {
            st.push(val++);
            ans.push_back('+');
        }

        // pop
        if (!st.empty() && st.top() == v[i]) {
            st.pop();
            ans.push_back('-');
        }
    }

    if (!st.empty()) {
        cout << "NO" << endl;
        return 0;
    }

    for (char &c : ans) {
        cout << c << endl;
    }

    return 0;
}