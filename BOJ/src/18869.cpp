/**
 * @file 18869.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sort
 * @version 0.1
 * @date 2022-10-19 13:23
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

    int m, n;
    cin >> m >> n;

    auto comp = [&](const pair<int, int> &left, const pair<int, int> &right) -> bool
    {
        if (left.first == right.first)
            return left.second > right.second;
        return left.first < right.first;
    };

    vector<vector<pair<int, int>>> space(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int size;
            cin >> size;
            space[i].push_back({size, j});
        }
        sort(space[i].begin(), space[i].end(), comp);
    }

    vector<int> comb(m, 0);
    comb[m - 1] = comb[m - 2] = 1;

    int ans = 0;

    do
    {
        vector<int> p;
        for (int i = 0; i < m; i++)
        {
            if (comb[i] == 1)
                p.push_back(i);
        }

        bool correct = true;
        for (int i = 0; i < n; i++)
        {
            if (space[p[0]][i].second != space[p[1]][i].second)
            {
                correct = false;
                break;
            }
        }

        if (correct)
            ans++;
    } while (next_permutation(comb.begin(), comb.end()));

    cout << ans << endl;

    return 0;
}