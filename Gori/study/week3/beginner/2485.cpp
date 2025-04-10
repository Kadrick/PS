/**
 * @file 2485.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 15:15
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int32_t main(void) {
    fastio;

    int n, range;
    cin >> n;
    vector<int> arr(n);
    vector<int> sub(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; ++i) {
        sub[i] = arr[i + 1] - arr[i];
    }

    range = sub[0];
    for (int i = 1; i < n - 1; ++i) {
        range = gcd(range, sub[i]);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += (sub[i] / range) - 1;
    }

    cout << ans;

    return 0;
}