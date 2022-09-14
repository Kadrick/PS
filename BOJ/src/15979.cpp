/**
 * @file 15979.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-09-08 14:26
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

    int n, m, g;
    cin >> n >> m;
    n = abs(n);
    m = abs(m);

    if (n == 0 && m == 0)
        cout << 0 << endl;
    else if (m + n < 2)
        cout << 1 << endl;
    else if (m == 0 || n == 0)
        cout << 2 << endl;
    else if (gcd(n, m) == 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;

    return 0;
}