/**
 * @file b.cpp
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

    int n, x, sum = 0, ans = 0;
    cin >> n >> x;
    vector<int> points(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> points[i];
        sum += points[i];
    }

    sort(points.begin(), points.end());

    if (sum - points[n - 2] >= x)
        cout << 0 << endl;
    else {
        int required = x - (sum - points[0]);

        if (required > 0)
            cout << -1 << endl;
        else
            cout << points[n - 2] + required << endl;
    }

    return 0;
}