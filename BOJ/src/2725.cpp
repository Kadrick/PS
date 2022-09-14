/**
 * @file 2725.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-09-08 13:54
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

int gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

int main(void)
{
    fastio;

    vector<int> ans(1001, 0);
    ans[1] = 2;
    for (int i = 1; i <= 1000; i++)
    {
        ans[i] += ans[i - 1];
        for (int j = 1; j < i; j++)
        {
            if (gcd(j, i) == 1)
                ans[i]++;
            if (gcd(i, j) == 1)
                ans[i]++;
        }
        if (gcd(i, i) == 1)
            ans[i]++;
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}