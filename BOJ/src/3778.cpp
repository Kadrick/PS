/**
 * @file 3778.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief string
 * @version 0.1
 * @date 2022-09-08 13:14
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

int solve()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<int> aCnt(26, 0), bCnt(26, 0);
    for (int i = 0; i < a.length(); i++)
        aCnt[a[i] - 'a']++;

    for (int i = 0; i < b.length(); i++)
        bCnt[b[i] - 'a']++;

    int ret = 0;

    for (int i = 0; i < 26; i++)
        ret += abs(aCnt[i] - bCnt[i]);

    return ret;
}

int main(void)
{
    fastio;

    int tc;
    cin >> tc;
    string tmp;
    getline(cin, tmp);

    for (int i = 0; i < tc; i++)
        cout << "Case #" << i + 1 << ": " << solve() << endl;

    return 0;
}