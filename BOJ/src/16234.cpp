/**
 * @file 16234.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS 23m
 * @version 0.1
 * @date 2022-10-19 15:24
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

    int n, l, r;
    cin >> n >> l >> r;

    vector<vector<int>> people(n, vector<int>(n));
    auto inRange = [&](int &y, int &x) -> bool
    {
        return 0 <= y && y < n && 0 <= x && x < n;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> people[i][j];
    }

    int ans = 0;
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};

    while (true)
    {
        bool isMove = false;

        vector<vector<bool>> visit(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit[i][j])
                    continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = true;

                int sum = people[i][j];
                vector<pair<int, int>> change;
                change.push_back({i, j});

                while (!q.empty())
                {
                    auto here = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int ny = here.first + dy[i];
                        int nx = here.second + dx[i];

                        if (!inRange(ny, nx) || visit[ny][nx])
                            continue;

                        int sub = abs(people[here.first][here.second] - people[ny][nx]);

                        if (l <= sub && sub <= r)
                        {
                            change.push_back({ny, nx});
                            visit[ny][nx] = true;
                            q.push({ny, nx});
                            sum += people[ny][nx];
                        }
                    }
                }

                if (change.size() > 1)
                {
                    isMove = true;
                    for (int k = 0; k < change.size(); k++)
                        people[change[k].first][change[k].second] = sum / change.size();
                }
            }
        }

        if (!isMove)
            break;

        ans++;
    }

    cout << ans << endl;

    return 0;
}