/**
 * @file 1654.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 15:10
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

int32_t main(int argc, char **argv) {
    fastio;

    int K, N;
    cin >> K >> N;

    long long left = 1, right = 0, ans = 0;

    vector<long long> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
        right = max(right, v[i]);
    }

    while (left <= right) {
        long long mid = (left + right) / 2;

        int cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += v[i] / mid;
        }

        if (cnt >= N) {
            ans = max(ans, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}