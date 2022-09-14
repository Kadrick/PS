/**
 * @file 2288.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-09-14 15:57
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

bool inRange(int n, int m, int r, int c)
{
    return r >= 0 || r < n || c >= 0 || c < m;
}

int main(void)
{
    fastio;

    int dx[] = {1, 0, -1};
    int dy[] = {0, 1, 0};

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == m && n == 0)
            break;

        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            string input;
            cin >> input;
            board.push_back(input);
        }

        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        bool top, bottom;
        top = bottom = false;
        for (int j = 0; j < m - 1; j++)
        {
            if (!top && board[0][j] == 'S' && board[0][j + 1] != 'S' && j != m - 2)
            {
                board[0][j + 1] = 'S';
                top = true;
            }
            if (!bottom && board[n - 1][j] == 'S' && board[n - 1][j + 1] != 'S' && j != m - 2)
            {
                board[n - 1][j + 1] = 'S';
                bottom = true;
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (board[i][j] == 'S' && board[i][j + 1] != 'S')
                {
                    board[i][j + 1] = 'S';
                    break;
                }
            }
        }

        for (int i = board[0].length() - 2; i > 0; i--)
        {
            if (board[0][i] == 'S')
            {
                q.push({1, {0, i}});
                visited[0][i] = true;
            }
        }

        int ans = 0;

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();

            if (current.second.first == n - 1)
            {
                ans = current.first;
                break;
            }

            for (int i = 0; i < 3; i++)
            {
                int ny = current.second.first + dy[i];
                int nx = current.second.second + dx[i];

                if (inRange(n, m, ny, nx) && !visited[ny][nx] && board[ny][nx] == 'S')
                {
                    q.push({current.first + 1, {ny, nx}});
                    visited[ny][nx] = true;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}