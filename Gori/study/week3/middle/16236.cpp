/**
 * @file 16236.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 15:59
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

typedef struct Point {
    int x;
    int y;
    Point(int y, int x) : x(x), y(y) {}
} Point;

int n, ans, fishSize = 2, eat = 0;
int board[21][21];
bool isVisited[21][21];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool inRange(int y, int x) { return 1 <= y && y <= n && 1 <= x && x <= n; }

Point start(0, 0);

void bfs(Point s) {
    memset(isVisited, false, sizeof(isVisited));
    queue<pair<Point, int>> q;
    q.push(make_pair(s, 0));

    int d = 987654321; // 가장 가까운 거리
    Point end(0, 0);   // 가장 가까운 점

    while (!q.empty()) {
        pair<Point, int> cur = q.front();
        q.pop();

        if (board[cur.first.y][cur.first.x] != 0 &&
            board[cur.first.y][cur.first.x] < fishSize) {
            if (cur.second == d) {
                if (end.y > cur.first.y) {
                    end.y = cur.first.y;
                    end.x = cur.first.x;
                } else if (end.y == cur.first.y) {
                    if (end.x > cur.first.x) {
                        end.y = cur.first.y;
                        end.x = cur.first.x;
                    }
                }

            } else if (cur.second < d) {
                d = cur.second;
                end.y = cur.first.y;
                end.x = cur.first.x;
            }
        }

        if (cur.second > d) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cur.first.x + dx[i];
            int ny = cur.first.y + dy[i];

            if (inRange(ny, nx) && !isVisited[ny][nx] &&
                board[ny][nx] <= fishSize) {
                q.push(make_pair(Point(ny, nx), cur.second + 1));
                isVisited[ny][nx] = true;
            }
        }
    }

    if (end.x == 0 && end.y == 0)
        return;

    ans += d;
    eat++;
    if (eat == fishSize) {
        fishSize++;
        eat = 0;
    }
    board[end.y][end.x] = 0;
    bfs(end);
}

int32_t main(void) {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                start.x = j;
                start.y = i;
                board[i][j] = 0;
            }
        }
    }

    bfs(start);

    cout << ans;

    return 0;
}