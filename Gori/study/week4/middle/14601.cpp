/**
 * @file 14601.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-08 11:21
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

int tile = 1;

bool checkBox(vector<vector<int>> &board, int left, int top, int n) {
    for (int i = top; i < top + n; i++) {
        for (int j = left; j < left + n; j++) {
            if (board[i][j] != 0)
                return false;
        }
    }
    return true;
}

void fillCenter(vector<vector<int>> &board, int left, int top, int n) {

    if (checkBox(board, left, top, n / 2)) {
        board[top + n / 2 - 1][left + n / 2 - 1] = tile;
    }

    if (checkBox(board, left + n / 2, top, n / 2)) {
        board[top + n / 2 - 1][left + n / 2] = tile;
    }

    if (checkBox(board, left, top + n / 2, n / 2)) {
        board[top + n / 2][left + n / 2 - 1] = tile;
    }

    if (checkBox(board, left + n / 2, top + n / 2, n / 2)) {
        board[top + n / 2][left + n / 2] = tile;
    }

    tile++;
}

void fill(vector<vector<int>> &board, int left, int top, int n) {

    fillCenter(board, left, top, n);

    if (n == 2)
        return;

    // left top
    fill(board, left, top, n / 2);
    // right top
    fill(board, left + n / 2, top, n / 2);
    // left down
    fill(board, left, top + n / 2, n / 2);
    // right down
    fill(board, left + n / 2, top + n / 2, n / 2);
}

int32_t main(int argc, char **argv) {
    fastio;

    int k, x, y;
    cin >> k >> x >> y;

    int n = (1 << k);
    vector<vector<int>> board(n, vector<int>(n, 0));

    board[y - 1][x - 1] = -1;

    fill(board, 0, 0, n);

    /*========================================================================*/

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}