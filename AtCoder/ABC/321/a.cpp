/**
 * @file a.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-23 20:57
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

int main(void) {
    fastio;

    string n;
    cin >> n;

    bool chk = true;

    for (int i = 0; n.length() > 1 && i < n.length() - 1; i++) {
        if (n[i] - '0' <= n[i + 1] - '0') {
            chk = false;
            break;
        }
    }

    if (chk)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}