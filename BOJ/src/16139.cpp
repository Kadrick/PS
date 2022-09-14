/**
 * @file 16139.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief string
 * @version 0.1
 * @date 2022-09-06 10:43
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

int cnt[200001][26] = {0};

int main(void)
{
    fastio;

    string input;
    cin >> input;

    cnt[1][input[0] - 'a']++;
    for (int i = 2; i <= input.length(); i++)
    {
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][input[i - 1] - 'a']++;
    }

    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        char alpha;
        int start, end;
        cin >> alpha >> start >> end;
        cout << cnt[end + 1][alpha - 'a'] - cnt[start][alpha - 'a'] << endl;
    }

    return 0;
}