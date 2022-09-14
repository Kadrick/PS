/**
 * @file 1956.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief FW
 * @version 0.1
 * @date 2022-09-01 13:54
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

const int inf = 1e9;

int main(void)
{
    fastio;

    int v, e;
    cin >> v >> e;
    int a, b, c;

    vector<vector<int>> dist(v + 1, vector<int>(v + 1, inf));

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int center = 1; center <= v; center++)
    {
        for (int start = 1; start <= v; start++)
        {
            for (int end = 1; end <= v; end++)
            {
                if (dist[start][center] + dist[center][end] < dist[start][end])
                    dist[start][end] = dist[start][center] + dist[center][end];
            }
        }
    }

    int ans = inf;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i == j)
                continue;
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }

    cout << (ans == inf ? -1 : ans) << endl;

    return 0;
}