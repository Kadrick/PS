/**
 * @file 17472.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief MST + BFS
 * @version 0.1
 * @date 2022-12-06 09:23
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

int n, m, cnt = 1;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void island(int id, int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    board[y][x] = id;
    visited[y][x] = true;

    while (!q.empty())
    {
        auto here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = here.first + dy[i];
            int nx = here.second + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m)
            {
                if (board[ny][nx] != 0 && !visited[ny][nx])
                {
                    board[ny][nx] = id;
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

vector<int> parent;

int findParent(int target)
{
    if (target == parent[target])
        return target;
    return parent[target] = findParent(parent[target]);
}

bool merge(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if (u != v)
    {
        parent[max(u, v)] = min(u, v);
        return true;
    }
    return false;
}

int main(void)
{
    fastio;

    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0 && !visited[i][j])
                island(cnt++, i, j);
        }
    }

    parent.resize(cnt, 0);
    for (int i = 0; i < cnt; i++)
        parent[i] = i;
    cnt--;

    vector<pair<int, pair<int, int>>> edges;

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0)
            {
                len = 0;
                // up
                for (int up = i - 1; up >= 0; up--)
                {
                    if (board[up][j] == 0)
                        len++;
                    else
                    {
                        if (len >= 2 && board[up][j] != board[i][j])
                            edges.push_back({len, {board[i][j], board[up][j]}});
                        break;
                    }
                }

                // down
                len = 0;
                for (int down = i + 1; down < n; down++)
                {
                    if (board[down][j] == 0)
                        len++;
                    else
                    {
                        if (len >= 2 && board[down][j] != board[i][j])
                            edges.push_back({len, {board[i][j], board[down][j]}});
                        break;
                    }
                }

                // left
                len = 0;
                for (int left = j - 1; left >= 0; left--)
                {
                    if (board[i][left] == 0)
                        len++;
                    else
                    {
                        if (len >= 2 && board[i][left] != board[i][j])
                            edges.push_back({len, {board[i][j], board[i][left]}});
                        break;
                    }
                }

                // right
                len = 0;
                for (int right = j + 1; right < m; right++)
                {
                    if (board[i][right] == 0)
                        len++;
                    else
                    {
                        if (len >= 2 && board[i][right] != board[i][j])
                            edges.push_back({len, {board[i][j], board[i][right]}});
                        break;
                    }
                }
            }
        }
    }

    sort(edges.begin(), edges.end());

    int ans = 0, e = cnt;
    cnt = 0;

    for (auto &&edge : edges)
    {
        if (merge(edge.second.first, edge.second.second))
        {
            ans += edge.first;
            cnt++;
        }
    }

    if (cnt == e - 1)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}