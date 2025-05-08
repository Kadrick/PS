/**
 * @file 1992.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-07 15:42
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

void compress(vector<vector<char>> &video, int x, int y, int size) {

    if (size == 1) {
        cout << video[x][y];
        return;
    }

    int next_size = size / 2;

    int val = video[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (video[i][j] != val) {
                cout << "(";
                compress(video, x, y, next_size);
                compress(video, x, y + next_size, next_size);
                compress(video, x + next_size, y, next_size);
                compress(video, x + next_size, y + next_size, next_size);
                cout << ")";
                return;
            }
        }
    }
    cout << val - '0';
}

int32_t main(int argc, char **argv) {
    fastio;

    int N;
    cin >> N;

    vector<vector<char>> video(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> video[i][j];
        }
    }

    compress(video, 0, 0, N);

    return 0;
}