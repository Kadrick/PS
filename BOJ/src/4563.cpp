/**
 * @file 4563.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-11-21 16:43
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
        long long a;
        cin >> a;

        if (!a)
            break;

        int ans = 0;
        long long a2 = a * a;

        for (long long i = 1; i < a; i++)
        {
            if (a2 % i == 0)
            {
                long long big = a2 / i;
                long long sm = i;

                long long sum = big + sm;
                long long sub = big - sm;

                if (sum % 2 == 0 && sub % 2 == 0 && sub / 2 > a)
                    ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}