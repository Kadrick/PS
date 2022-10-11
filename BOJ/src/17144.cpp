/**
 * @file 17144.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-10-11 16:08
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

int R, C, T;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int row, int col)
{
    return 0 <= row && row < R &&
           0 <= col && col < C;
}

vector<vector<int>> room;
vector<int> cleaner;

void diffusion()
{
    vector<vector<int>> diffusionTable(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] > 0)
            {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];

                    if (inRange(ny, nx) && room[ny][nx] != -1)
                    {
                        cnt++;
                        diffusionTable[ny][nx] += room[i][j] / 5;
                    }
                }

                if (cnt > 0)
                    room[i][j] -= (room[i][j] / 5) * cnt;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            room[i][j] += diffusionTable[i][j];
    }
}

void cleaning()
{
    // counter clockwise
    room[cleaner[0] - 1][0] = 0;
    for (int i = cleaner[0] - 2; i >= 0; i--)
        room[i + 1][0] = room[i][0];

    for (int i = 1; i < C; i++)
        room[0][i - 1] = room[0][i];

    for (int i = 1; i <= cleaner[0]; i++)
        room[i - 1][C - 1] = room[i][C - 1];

    for (int i = C - 2; i >= 1; i--)
        room[cleaner[0]][i + 1] = room[cleaner[0]][i];
    room[cleaner[0]][1] = 0;

    // clockwise
    room[cleaner[1] + 1][0] = 0;
    for (int i = cleaner[1] + 1; i < R - 1; i++)
        room[i][0] = room[i + 1][0];

    for (int i = 1; i < C; i++)
        room[R - 1][i - 1] = room[R - 1][i];

    for (int i = R - 2; i >= cleaner[1]; i--)
        room[i + 1][C - 1] = room[i][C - 1];

    for (int i = C - 2; i >= 1; i--)
        room[cleaner[1]][i + 1] = room[cleaner[1]][i];
    room[cleaner[1]][1] = 0;
}

void printRoom()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << room[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void simulate()
{
    diffusion();
    // printRoom();

    cleaning();
    // printRoom();
}

int totalDust()
{
    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] != -1)
                ans += room[i][j];
        }
    }

    return ans;
}

int main(void)
{
    fastio;

    cin >> R >> C >> T;

    room.resize(R, vector<int>(C, 0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> room[i][j];

            if (room[i][j] == -1)
                cleaner.push_back(i);
        }
    }

    while (T--)
        simulate();

    cout << totalDust() << endl;

    return 0;
}