/**
 * @file 6593.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-07 09:33
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

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main(void)
{
    fastio;

    while (true)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;

        vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(r, vector<bool>(c, false)));
        vector<vector<string>> building(l, vector<string>(r, ""));
        queue<pair<int, tuple<int, int, int>>> q;

        auto inRange = [&](int z, int y, int x) -> bool
        {
            return 0 <= z && z < l &&
                   0 <= y && y < r &&
                   0 <= x && x < c;
        };

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    char ch;
                    cin >> ch;

                    if (ch == 'S')
                    {
                        q.push({0, make_tuple(i, j, k)});
                        visited[i][j][k] = true;
                    }
                    building[i][j].push_back(ch);
                }
            }
        }

        int ans = -1;
        while (!q.empty())
        {
            auto here = q.front();
            q.pop();

            int level, row, col;
            tie(level, row, col) = here.second;

            if (building[level][row][col] == 'E')
            {
                ans = here.first;
                break;
            }

            for (int i = 0; i < 6; i++)
            {
                int nl = level + dz[i];
                int nr = row + dy[i];
                int nc = col + dx[i];

                if (inRange(nl, nr, nc) && building[nl][nr][nc] != '#' && !visited[nl][nr][nc])
                {
                    q.push({here.first + 1, make_tuple(nl, nr, nc)});
                    visited[nl][nr][nc] = true;
                }
            }
        }

        if (ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    return 0;
}