/**
 * @file 1450.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief meet in the middle
 * @version 0.1
 * @date 2022-10-26 15:30
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

#define int long long

void select(int sum, const int &bag, int start, int end, const vector<int> &arr, vector<int> &candidate)
{
    if (start > end)
    {
        if (sum <= bag)
            candidate.push_back(sum);
        return;
    }

    select(sum + arr[start], bag, start + 1, end, arr, candidate);
    select(sum, bag, start + 1, end, arr, candidate);
}

int32_t main(void)
{
    fastio;

    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> left, right;
    select(0, c, 0, n / 2 - 1, arr, left);
    select(0, c, n / 2, n - 1, arr, right);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int ans = 0;
    for (int i = 0; i < left.size(); i++)
    {
        int possibleSize = upper_bound(right.begin(), right.end(), c - left[i]) - right.begin();
        ans += possibleSize;
    }
    cout << ans << endl;

    return 0;
}