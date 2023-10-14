/**
 * @file a.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16 21:00
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

    long long a, b;
    cin >> a >> b;

    cout << fixed << int(pow(a, b) + pow(b, a)) << endl;

    return 0;
}