/**
 * @file 4419.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement 1h 40m
 * @version 0.1
 * @date 2022-10-20 09:08
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

    int n;
    cin >> n;
    vector<string> name;
    string space;
    getline(cin, space);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        name.push_back(tmp);
    }

    vector<bool> drop(n, false);
    vector<queue<int>> vote;

    int cnt = 0, tmp;
    while (cin >> tmp)
    {
        vote.push_back(queue<int>());
        vote[cnt].push(tmp - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> tmp;
            vote[cnt].push(tmp - 1);
        }
        cnt++;
    }

    for (;;)
    {
        vector<int> candidate(n, 0);
        int week = INT_MAX;
        int strong = 0;

        for (int ballot = 0; ballot < cnt; ballot++)
        {
            while (!vote[ballot].empty())
            {
                if (!drop[vote[ballot].front()])
                    break;
                vote[ballot].pop();
            }

            if (!vote[ballot].empty())
                candidate[vote[ballot].front()]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (drop[i])
                continue;
            strong = max(strong, candidate[i]);
            week = min(week, candidate[i]);
        }

        if (strong * 2 > cnt || strong == week)
        {
            for (int i = 0; i < n; i++)
            {
                if (drop[i])
                    continue;

                if (candidate[i] == strong)
                    cout << name[i] << endl;
            }
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (drop[i])
                continue;
            if (candidate[i] == week)
                drop[i] = true;
        }
    }

    return 0;
}