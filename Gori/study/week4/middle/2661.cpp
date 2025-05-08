/**
 * @file 2661.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 15:48
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

bool make_sequence(string &s, int N) {

    for (int i = 1; i <= s.length() / 2; i++) {
        string a = s.substr(s.length() - i, i);
        string b = s.substr(s.length() - 2 * i, i);

        if (a == b)
            return false;
    }

    if (s.length() == N) {
        return true;
    }

    for (int i = 1; i <= 3; i++) {
        if (s.back() == i + '0')
            continue;

        s.push_back(i + '0');

        if (make_sequence(s, N))
            return true;

        s.pop_back();
    }

    return false;
}

int32_t main(int argc, char **argv) {
    fastio;

    int N;
    cin >> N;

    string s = "1";

    make_sequence(s, N);

    cout << s;

    return 0;
}