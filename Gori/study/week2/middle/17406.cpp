/**
 * @file 17406.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-03 13:49
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

void print(const vector<vector<int>> &arr) {
    cout << endl << "--------------------" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int value(const vector<vector<int>> &arr) {
    int ret = INT32_MAX;
    for (int i = 0; i < arr.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < arr[i].size(); j++) {
            tmp += arr[i][j];
        }
        ret = min(ret, tmp);
    }
    return ret;
}

void rotateRight(vector<vector<int>> &arr, int n, int m, int ms) {
    int s = 1;
    while (s <= ms) {
        vector<int> tmp;

        for (int i = m - s; i < m + s; i++) {
            tmp.push_back(arr[n - s][i]);
        }
        for (int i = n - s; i < n + s; i++) {
            tmp.push_back(arr[i][m + s]);
        }
        for (int i = m + s; i > m - s; i--) {
            tmp.push_back(arr[n + s][i]);
        }
        for (int i = n + s; i > n - s; i--) {
            tmp.push_back(arr[i][m - s]);
        }

        int idx = (-1 + tmp.size()) % tmp.size();

        for (int i = m - s; i < m + s; i++) {
            arr[n - s][i] = tmp[idx];
            idx = (idx + 1) % tmp.size();
        }
        for (int i = n - s; i < n + s; i++) {
            arr[i][m + s] = tmp[idx];
            idx = (idx + 1) % tmp.size();
        }
        for (int i = m + s; i > m - s; i--) {
            arr[n + s][i] = tmp[idx];
            idx = (idx + 1) % tmp.size();
        }
        for (int i = n + s; i > n - s; i--) {
            arr[i][m - s] = tmp[idx];
            idx = (idx + 1) % tmp.size();
        }

        s++;
    }
}

int32_t main(int argc, char **argv) {
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> batch;
    vector<tuple<int, int, int>> op;
    for (int i = 0; i < k; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        op.push_back({r - 1, c - 1, s});
        batch.push_back(i);
    }

    int ret = INT32_MAX;

    do {

        auto tmp = arr;

        for (int i = 0; i < k; i++) {
            auto [r, c, s] = op[batch[i]];
            rotateRight(tmp, r, c, s);
            // print(tmp);
        }
        ret = min(ret, value(tmp));

    } while (next_permutation(batch.begin(), batch.end()));

    cout << ret << endl;

    return 0;
}