/**
 * @file c.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14 20:58
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

bool check(const string &origin, const string &t) {
    if (origin == t)
        return true;

    if (t == t[0] + origin)
        return true;

    // add
    if (origin.length() < t.length()) {
        int shield = 0;
        for (int i = 0; i < t.size(); i++) {
            if (origin[i - shield] != t[i]) {
                if (!shield)
                    shield++;
                else
                    return false;
            }
        }

        return true;
    }

    // delete
    if (origin.length() > t.length()) {
        int shield = 0;
        for (int i = 0; i < origin.size(); i++) {
            if (origin[i] != t[i - shield]) {
                if (!shield)
                    shield++;
                else
                    return false;
            }
        }

        return true;
    }

    // change
    if (origin.length() == t.length()) {
        bool shield = true;
        for (int i = 0; i < origin.length(); i++) {
            if (origin[i] != t[i]) {
                if (shield)
                    shield = false;
                else
                    return false;
            }
        }

        return true;
    }

    return false;
}

int main(void) {
    fastio;

    int n;
    string aoki;
    cin >> n >> aoki;

    vector<int> ans;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<string, int> um;
    for (int i = 0; i < n; i++) {

        if (um.find(arr[i]) != um.end()) {
            ans.push_back(i);
            continue;
        }

        bool flag = check(arr[i], aoki);

        if (flag) {
            ans.push_back(i);
            um[arr[i]] = i;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";

    return 0;
}