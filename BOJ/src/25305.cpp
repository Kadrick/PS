/**
 * @file 25305.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief sorting
 * @version 0.1
 * @date 2022-08-22 09:03
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

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end(), greater<int>());

    cout << arr[k - 1] << endl;

    return 0;
}