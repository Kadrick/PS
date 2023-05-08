/**
 * @file 25208.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

int main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    /* ------------------------------- Input Board ------------------------------ */
    pair<int, int> start, end;
    vector<vector<char>> board(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'D')
                start = {i, j};

            if (board[i][j] == 'R')
                end = {i, j};
        }
    }
    /* ---------------------------------- Setup --------------------------------- */
    int ans = -1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    enum STATE
    {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT,
        FRONT,
        BACK
    };

    auto checkEdge = [&](int x, int y) -> bool
    {
        if (x > 0 && x < m - 1 && y > 0 && y < n - 1)
            return false;
        return true;
    };

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(6, false)));
    visited[start.first][start.second][STATE::BOTTOM] = true;

    queue<pair<pair<int, int>, pair<STATE, int>>> q;
    q.push({start, {STATE::BOTTOM, 0}});

    /* ----------------------------------- BFS ---------------------------------- */
    while (!q.empty())
    {
        auto here = q.front().first;
        auto state = q.front().second.first;
        auto step = q.front().second.second;
        q.pop();

        if (here == end)
        {
            if (state == STATE::BOTTOM)
            {
                ans = step;
                break;
            }

            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (checkEdge(nx, ny) || board[ny][nx] == '#')
                continue;

            STATE nextState;

            // i = left, right, down, up
            switch (state)
            {
            case STATE::BOTTOM:
                if (i == 0)
                    nextState = STATE::RIGHT;
                if (i == 1)
                    nextState = STATE::LEFT;
                if (i == 2)
                    nextState = STATE::FRONT;
                if (i == 3)
                    nextState = STATE::BACK;
                break;
            case STATE::TOP:
                if (i == 0)
                    nextState = STATE::LEFT;
                if (i == 1)
                    nextState = STATE::RIGHT;
                if (i == 2)
                    nextState = STATE::BACK;
                if (i == 3)
                    nextState = STATE::FRONT;
                break;
            case STATE::LEFT:
                if (i == 0)
                    nextState = STATE::BOTTOM;
                if (i == 1)
                    nextState = STATE::TOP;
                if (i == 2)
                    nextState = STATE::LEFT;
                if (i == 3)
                    nextState = STATE::LEFT;
                break;
            case STATE::RIGHT:
                if (i == 0)
                    nextState = STATE::TOP;
                if (i == 1)
                    nextState = STATE::BOTTOM;
                if (i == 2)
                    nextState = STATE::RIGHT;
                if (i == 3)
                    nextState = STATE::RIGHT;
                break;
            case STATE::FRONT:
                if (i == 0)
                    nextState = STATE::FRONT;
                if (i == 1)
                    nextState = STATE::FRONT;
                if (i == 2)
                    nextState = STATE::TOP;
                if (i == 3)
                    nextState = STATE::BOTTOM;
                break;
            case STATE::BACK:
                if (i == 0)
                    nextState = STATE::BACK;
                if (i == 1)
                    nextState = STATE::BACK;
                if (i == 2)
                    nextState = STATE::BOTTOM;
                if (i == 3)
                    nextState = STATE::TOP;
                break;
            }

            if (visited[ny][nx][nextState])
                continue;

            visited[ny][nx][nextState] = true;
            q.push({{ny, nx}, {nextState, step + 1}});
        }
    }

    cout << ans << endl;

    return 0;
}