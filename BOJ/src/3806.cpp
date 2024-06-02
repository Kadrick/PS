/**
 * @file 3806.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int main(void) {
    fastio;

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        string s, t;
        cin >> s >> t;

        int ans = 0;

        vector<int> zeroOne, oneZero, qZero, qOne;

        for (int j = 0; j < s.length(); j++) {
            if (s[j] == t[j]) {
                continue;
            }

            if (s[j] == '0' && t[j] == '1')
                zeroOne.push_back(j);
            if (s[j] == '1' && t[j] == '0')
                oneZero.push_back(j);
            if (s[j] == '?' && t[j] == '0')
                qZero.push_back(j);
            if (s[j] == '?' && t[j] == '1')
                qOne.push_back(j);
        }

        bool flag = true;
        int noQTrade = min(zeroOne.size(), oneZero.size());
        int qTrade = 0;

        if (zeroOne.size() - noQTrade > 0) {
            ans += zeroOne.size() - noQTrade;
        }

        if (oneZero.size() - noQTrade > 0) {
            if (qOne.size() >= oneZero.size() - noQTrade) {
                qTrade = (oneZero.size() - noQTrade) * 2;
            } else {
                flag = false;
            }
        }

        ans += noQTrade;
        ans += qTrade;
        ans += qZero.size();
        ans += qOne.size() - (qTrade / 2);

        cout << "Case " << i + 1 << ": " << (flag ? ans : -1) << endl;
    }

    return 0;
}