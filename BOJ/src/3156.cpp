/**
 * @file 3156.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Sort
 * @version 0.1
 * @date 2022-09-14 17:25
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

    map<string, int> uniqueTable;
    vector<pair<int, string>> musics;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        int music, minRank;
        cin >> music >> tmp >> minRank;

        for (int j = 0; j < music; j++)
        {
            string name;
            cin >> name;
            if (uniqueTable.find(name) == uniqueTable.end())
                uniqueTable[name] = minRank;
            else
                uniqueTable[name] = min(uniqueTable[name], minRank);
        }
    }

    for (auto iter = uniqueTable.begin(); iter != uniqueTable.end(); iter++)
        musics.push_back({(*iter).second, (*iter).first});

    if (musics.size() == 1)
    {
        cout << musics[0].first << ' ' << musics[0].second << endl;
        return 0;
    }

    sort(musics.begin(), musics.end(),
         [&](pair<int, string> &left, pair<int, string> &right) -> bool
         {
             return left.first < right.first;
         });

    for (int i = 0; i < musics.size(); i++)
    {
        if (musics[i].first == i + 1)
        {
            if (i == 0)
            {
                if (musics[i].first != musics[i + 1].first)
                    cout << musics[i].first << ' ' << musics[i].second << endl;
            }
            else if (i == musics.size() - 1)
            {
                if (musics[i].first != musics[i - 1].first)
                    cout << musics[i].first << ' ' << musics[i].second << endl;
            }
            else
            {
                if (musics[i].first != musics[i + 1].first && musics[i].first != musics[i - 1].first)
                    cout << musics[i].first << ' ' << musics[i].second << endl;
            }
        }
    }

    return 0;
}