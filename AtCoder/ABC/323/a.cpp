/**
 * @file a.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07 20:57
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

    string input;
    cin >> input;

    for (int i = 1; i < 16; i += 2) {
        if (input[i] == '1') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}