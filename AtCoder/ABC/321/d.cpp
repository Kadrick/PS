/**
 * @file d.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-23 20:58
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

    long long n, m, p;
    cin >> n >> m >> p;

    vector<long long> main(n), side(m);
    for (int i = 0; i < n; i++)
        cin >> main[i];
    for (int i = 0; i < m; i++)
        cin >> side[i];

    sort(main.begin(), main.end());
    sort(side.begin(), side.end());

    vector<long long> fsum(m + 1);
    fsum[0] = 0;
    for (int i = 0; i < m; i++) {
        fsum[i + 1] = side[i] + fsum[i];
    }

    long long sum = 0;

    for (int i = 0; i < n; i++) {

        long long val = p - main[i];
        long long idx =
            lower_bound(side.begin(), side.end(), val) - side.begin();

        sum += (m - idx) * p;
        sum += main[i] * idx + fsum[idx];
    }

    cout << sum << endl;

    return 0;
}