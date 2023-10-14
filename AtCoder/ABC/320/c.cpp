/**
 * @file c.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-16 21:32
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

    int m;
    vector<string> input(3);

    cin >> m;
    for (int i = 0; i < 3; i++)
        cin >> input[i];

    int t = INT_MAX;

    for (int i = 0; i < m * 3; i++) {
        for (int j = 0; j < m * 3; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < m * 3; k++) {
                if (j == k)
                    continue;

                if (i == k)
                    continue;

                if (input[0][i % m] == input[1][j % m] &&
                    input[0][i % m] == input[2][k % m])
                    t = min(t, max({i, j, k}));
            }
        }
    }

    if (t == INT_MAX)
        t = -1;

    cout << t << endl;

    return 0;
}