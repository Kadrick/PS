/**
 * @file 22359.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-05-08 13:34
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

bool checkBox(vector<vector<char>> &board, int left, int top, int n) {
    for (int i = top; i < top + n; i++) {
        for (int j = left; j < left + n; j++) {
            if (board[i][j] != '.')
                return false;
        }
    }
    return true;
}

void fillCenter(vector<vector<char>> &board, int left, int top, int n, int color) {

    char c = color ? 'a' : 'b';
    if (n != 2)
        c = 'c';

    if (checkBox(board, left, top, n / 2)) {
        board[top + n / 2 - 1][left + n / 2 - 1] = c;
    }

    if (checkBox(board, left + n / 2, top, n / 2)) {
        board[top + n / 2 - 1][left + n / 2] = c;
    }

    if (checkBox(board, left, top + n / 2, n / 2)) {
        board[top + n / 2][left + n / 2 - 1] = c;
    }

    if (checkBox(board, left + n / 2, top + n / 2, n / 2)) {
        board[top + n / 2][left + n / 2] = c;
    }
}

void fill(vector<vector<char>> &board, int left, int top, int n, int color) {

    fillCenter(board, left, top, n, color);

    if (n == 2)
        return;

    // left top
    fill(board, left, top, n / 2, 1);
    // right top
    fill(board, left + n / 2, top, n / 2, 0);
    // left down
    fill(board, left, top + n / 2, n / 2, 0);
    // right down
    fill(board, left + n / 2, top + n / 2, n / 2, 1);
}

int32_t main(int argc, char **argv) {
    fastio;

    int t, k;
    cin >> t >> k;
    int n = (1 << k);

    while (t--) {
        int x, y;
        cin >> x >> y;

        vector<vector<char>> board(n, vector<char>(n, '.'));

        board[x - 1][y - 1] = '@';

        fill(board, 0, 0, n, 0);

        /*========================================================================*/

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}