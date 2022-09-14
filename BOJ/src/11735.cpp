/**
 * @file 11735.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
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

char dir;
long long n, q, idx, sum, ans;
long long info[2][2];
bool visited_row[1000001];
bool visited_col[1000001];

int main(void)
{
    fastio;

    cin >> n >> q;

    sum = (n + 1) * n / 2;
    for (int i = 0; i < q; i++)
    {
        cin >> dir >> idx;

        if (dir == 'R')
        {

            if (visited_row[idx])
                cout << 0 << endl;
            else
            {
                visited_row[idx] = true;
                ans = (n - info[1][0]) * idx + sum - info[1][1];
                cout << ans << endl;
                info[0][0]++;
                info[0][1] += idx;
            }
        }
        else
        {
            if (visited_col[idx])
                cout << 0 << endl;
            else
            {
                visited_col[idx] = true;
                ans = (n - info[0][0]) * idx + sum - info[0][1];
                cout << ans << endl;
                info[1][0]++;
                info[1][1] += idx;
            }
        }
    }

    return 0;
}