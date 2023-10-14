/**
 * @file b.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16 21:03
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

    for (int length = input.length(); length > 0; length--) {

        // check palindrome
        for (int start = 0; start < input.length() - length + 1; start++) {
            bool chk = true;

            for (int j = 0; j < length / 2; j++) {
                if (input[start + j] != input[start + length - 1 - j]) {
                    chk = false;
                    break;
                }
            }

            if (chk) {
                cout << length << endl;
                return 0;
            }
        }
    }

    cout << 1 << endl;

    return 0;
}