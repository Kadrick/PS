/**
 * @file 21870.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Divide & Conquer 46m
 * @version 0.1
 * @date 2022-10-26 09:20
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

int Gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return Gcd(b, a % b);
}

int solve(const vector<int> &arr, int start, int end)
{
    int size = end - start + 1;

    if (size <= 3)
    {
        int ret = 0;
        for (int i = start; i <= end; i++)
            ret += arr[i];
        return ret;
    }

    int left = size / 2;

    int LGcd = arr[start];
    for (int i = start + 1; i < start + left; i++)
        LGcd = Gcd(LGcd, arr[i]);
    int lmax = LGcd + solve(arr, start + left, end);

    int RGcd = arr[start + left];
    for (int i = start + left; i <= end; i++)
        RGcd = Gcd(RGcd, arr[i]);
    int rmax = RGcd + solve(arr, start, start + left - 1);

    return max(lmax, rmax);
}

int main(void)
{
    fastio;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, 0, n - 1) << endl;

    return 0;
}