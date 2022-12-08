/**
 * @file 14502.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-12-08 14:59
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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int chk(vector<vector<int>> board)
{
    int height = board.size();
    int width = board[0].size();

    vector<vector<bool>> visited(height, vector<bool>(width, false));

    auto inRange = [&](int y, int x) -> bool
    {
        return 0 <= y && y < height && 0 <= x && x < width;
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] == 2 && !visited[i][j])
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    auto here = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int ny = here.first + dy[dir];
                        int nx = here.second + dx[dir];

                        if (inRange(ny, nx) && !visited[ny][nx] && board[ny][nx] == 0)
                        {
                            board[ny][nx] = 2;
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cnt += board[i][j] == 0 ? 1 : 0;
    }
    return cnt;
}

int main(void)
{
    fastio;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    int ans = 0;
    int totalSpace = n * m;

    for (int wall1 = 0; wall1 < totalSpace - 3; wall1++)
    {
        if (board[wall1 / m][wall1 % m] > 0)
            continue;
        for (int wall2 = wall1 + 1; wall2 < totalSpace - 2; wall2++)
        {
            if (board[wall2 / m][wall2 % m] > 0)
                continue;
            for (int wall3 = wall2 + 1; wall3 < totalSpace; wall3++)
            {
                if (board[wall3 / m][wall3 % m] > 0)
                    continue;
                board[wall1 / m][wall1 % m] =
                    board[wall2 / m][wall2 % m] =
                        board[wall3 / m][wall3 % m] = 1;

                ans = max(ans, chk(board));

                board[wall1 / m][wall1 % m] =
                    board[wall2 / m][wall2 % m] =
                        board[wall3 / m][wall3 % m] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}