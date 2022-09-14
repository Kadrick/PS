/**
 * @file 1789.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy, math
 * @version 0.1
 * @date 2021-12-16 21:50
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

long long s, ans;

int main(void)
{
    fastio;

    cin >> s;

    for (long long i = 0;; i++)
    {
        if ((i + 1) * i / 2 > s)
        {
            cout << i - 1 << endl;
            break;
        }
    }

    return 0;
}