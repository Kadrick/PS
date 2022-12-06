/**
 * @file 2981.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-12-06 13:40
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

int gcd(int a, int b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}

int main(void)
{
    fastio;

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num.begin(), num.end());

    int target = num[1] - num[0];
    for (int i = 1; i < n - 1; i++)
        target = gcd(num[i + 1] - num[i], target);

    vector<int> ans;
    for (int i = 1; i * i <= target; i++)
    {
        if (target % i == 0)
        {
            ans.push_back(i);
            if (i != target / i)
                ans.push_back(target / i);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}