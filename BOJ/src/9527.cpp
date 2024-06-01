/**
 * @file 9527.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date
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

long long get(long long n) {
    long long ans = 0;

    for (int i = 0; i <= log2(n); i++) {

        long long tmp = 0;

        long long oneNr = 1LL << i;
        long long block = (n + 1) / (oneNr * 2);
        long long after = (n + 1) % (oneNr * 2);

        tmp += oneNr * block;
        tmp += max(after - oneNr, 0LL);

        ans += tmp;
    }

    return ans;
}

int main(void) {
    fastio;

    long long a, b;
    cin >> a >> b;

    cout << get(b) - get(a - 1) << endl;

    return 0;
}