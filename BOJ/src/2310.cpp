/**
 * @file 2310.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS 39m
 * @version 0.1
 * @date 2022-10-24 16:48
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

    while (true)
    {
        int n;
        cin >> n;

        if (!n)
            break;

        vector<pair<char, int>> roomInfo(n);
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++)
        {
            cin >> roomInfo[i].first >> roomInfo[i].second;

            while (true)
            {
                int next;
                cin >> next;
                if (!next)
                    break;
                graph[i].push_back(next - 1);
            }
        }

        bool possible = false;
        vector<vector<bool>> visit(n, vector<bool>(501, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visit[0][0] = true;

        while (!q.empty())
        {
            int cur = q.front().first;
            int money = q.front().second;
            q.pop();

            if (roomInfo[cur].first == 'T')
            {
                if (money < roomInfo[cur].second)
                    continue;
                else
                    money -= roomInfo[cur].second;
            }

            if (roomInfo[cur].first == 'L')
                money = max(money, roomInfo[cur].second);

            if (cur == n - 1)
            {
                possible = true;
                break;
            }

            for (auto &&next : graph[cur])
            {
                if (visit[next][money])
                    continue;
                visit[next][money] = true;
                q.push({next, money});
            }
        }

        if (possible)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}