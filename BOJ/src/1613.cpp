/**
 * @file 1613.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Floyd-Warshall
 * @version 0.1
 * @date 2022-09-13 13:33
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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));

    for (int i = 0; i < k; i++)
    {
        int from, to;
        cin >> from >> to;
        dist[from][to] = 1;
    }

    for (int spot = 1; spot <= n; spot++)
    {
        for (int from = 1; from <= n; from++)
        {
            for (int to = 1; to <= n; to++)
            {
                if (dist[from][to] > dist[from][spot] + dist[spot][to])
                    dist[from][to] = dist[from][spot] + dist[spot][to];
            }
        }
    }

    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int from, to;
        cin >> from >> to;

        if (dist[from][to] != inf)
            cout << -1 << endl;
        else if (dist[to][from] != inf)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}