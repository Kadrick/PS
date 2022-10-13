/**
 * @file 16235.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-10-13 16:31
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

    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    vector<vector<int>> ground(n + 1, vector<int>(n + 1, 5));
    vector<vector<int>> compost(n + 1, vector<int>(n + 1, 0));
    vector<vector<deque<int>>> tree(n + 1, vector<deque<int>>(n + 1));

    int dx[8] = {0, -1, 1, 0, -1, -1, 1, 1};
    int dy[8] = {-1, 0, 0, 1, -1, 1, -1, 1};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> compost[i][j];
    }

    auto inRange = [&](int y, int x) -> bool
    {
        return 1 <= y && y <= n &&
               1 <= x && x <= n;
    };

    for (int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tree[i][j].size() == 0)
                continue;
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }

    while (k--)
    {
        // spring & summer
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (tree[i][j].size() == 0)
                    continue;

                int fence = -1;
                for (int id = 0; id < tree[i][j].size(); id++)
                {
                    if (ground[i][j] < tree[i][j][id])
                    {
                        fence = id;
                        break;
                    }
                    else
                    {
                        ground[i][j] -= tree[i][j][id];
                        tree[i][j][id] += 1;
                    }
                }

                if (fence != -1)
                {
                    int totalSize = tree[i][j].size();
                    for (int id = totalSize - 1; id >= fence; id--)
                    {
                        ground[i][j] += tree[i][j][id] / 2;
                        tree[i][j].pop_back();
                    }
                }
            }
        }

        // fall
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (tree[i][j].size() == 0)
                    continue;

                for (int id = 0; id < tree[i][j].size(); id++)
                {
                    if (tree[i][j][id] % 5 != 0)
                        continue;

                    for (int dir = 0; dir < 8; dir++)
                    {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];

                        if (!inRange(ny, nx))
                            continue;

                        tree[ny][nx].push_front(1);
                    }
                }
            }
        }

        // winter
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                ground[i][j] += compost[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    }

    cout << ans << endl;

    return 0;
}