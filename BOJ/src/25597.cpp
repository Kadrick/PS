/**
 * @file 25597.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-10-24 17:30
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

    int x, t;
    cin >> x >> t;

    if (t >= x || x % 4 == 0 || x % 8 == 0)
    {
        if (t >= x)
        {
            cout << 1 << endl;
            cout << t - x << ' ' << 1 << endl;
            return 0;
        }

        if (x % 8 == 0)
        {
            if (t >= x / 8)
            {
                cout << 1 << endl;
                cout << t - (x / 8) << ' ' << 8 << endl;
                return 0;
            }
        }
        if (x % 4 == 0)
        {
            if (t >= x / 4)
            {
                cout << 1 << endl;
                cout << t - (x / 4) << ' ' << 4 << endl;
                return 0;
            }
        }
    }

    int eight, four, one;

    int tmpX = x;
    // 8, 4
    eight = tmpX / 8;
    tmpX %= 8;
    four = tmpX / 4;
    tmpX %= 4;

    if (tmpX == 0 && t >= eight + four && eight != 0 && four != 0)
    {
        cout << 2 << endl;
        cout << t - (eight + four) << ' ' << 4 << endl;
        cout << t - eight << ' ' << 8 << endl;
        return 0;
    }

    // 4, 1
    tmpX = x;
    four = tmpX / 4;
    tmpX %= 4;
    one = tmpX / 1;
    tmpX %= 1;

    if (tmpX == 0 && t >= four + one && four != 0)
    {
        cout << 2 << endl;
        cout << t - (one + four) << ' ' << 1 << endl;
        cout << t - four << ' ' << 4 << endl;
        return 0;
    }

    // 8, 1
    tmpX = x;
    eight = tmpX / 8;
    tmpX %= 8;
    one = tmpX / 1;
    tmpX %= 1;

    if (tmpX == 0 && t >= eight + one && eight != 0)
    {
        cout << 2 << endl;
        cout << t - (eight + one) << ' ' << 1 << endl;
        cout << t - eight << ' ' << 8 << endl;
        return 0;
    }

    // 8,4,1
    tmpX = x;
    eight = tmpX / 8;
    tmpX %= 8;
    four = tmpX / 4;
    tmpX %= 4;
    one = tmpX / 1;
    tmpX %= 1;

    if (tmpX == 0 && t >= eight + four + one && eight != 0 && four != 0)
    {
        cout << 3 << endl;
        cout << t - (eight + four + one) << ' ' << 1 << endl;
        cout << t - (eight + four) << ' ' << 4 << endl;
        cout << t - eight << ' ' << 8 << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}