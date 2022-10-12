/**
 * @file 1113.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-10-12 10:37
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

int main(void)
{
    fastio;

    int n, m, ans = 0;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    auto inRange = [&](int y, int x) -> bool
    {
        return 0 <= y && y < n &&
               0 <= x && x < m;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            board[i][j] = ch - '0';
        }
    }

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    for (int target = 1; target < 10; target++)
    {
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (board[row][col] == target && !visit[row][col])
                {
                    bool isCalc = true;
                    queue<pair<int, int>> q;
                    int height = board[row][col], cnt = 0, wall = INT_MAX;
                    q.push({row, col});
                    visit[row][col] = true;

                    while (!q.empty())
                    {
                        auto here = q.front();
                        q.pop();

                        cnt++;

                        for (int k = 0; k < 4; k++)
                        {
                            int ny = here.first + dy[k];
                            int nx = here.second + dx[k];

                            if (!inRange(ny, nx))
                            {
                                isCalc = false;
                                continue;
                            }

                            if (board[ny][nx] > height)
                                wall = min(wall, board[ny][nx]);
                            else
                            {
                                if (visit[ny][nx])
                                    continue;
                                q.push({ny, nx});
                                visit[ny][nx] = true;
                            }
                        }
                    }

                    if (height < wall && isCalc && wall != INT_MAX)
                        ans += cnt * (wall - height);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}