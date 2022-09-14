/**
 * @file 23559.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sorting
 * @version 0.1
 * @date 2021-12-18 01:06
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

int n, x, a, b, ans, cnt;
vector<pair<int, int>> arr;

bool comp(const pair<int, int> &left, const pair<int, int> &right)
{
    return abs(left.first - left.second) > abs(right.first - right.second);
}

int main(void)
{
    fastio;

    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;

        if (a <= b)
        {
            x -= 1000;
            ans += b;
            cnt++;
            continue;
        }

        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < arr.size(); ++i)
    {
        auto& cur = arr[i];
        if (x >= 5000 && x - 5000 >= (n - cnt - 1) * 1000)
        {
            ans += cur.first;
            x -= 5000;
        }
        else
        {
            ans += cur.second;
            x -= 1000;
        }
        cnt++;
    }

    cout << ans << endl;

    return 0;
}