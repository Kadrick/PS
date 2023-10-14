/**
 * @file b.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-14 20:58
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int main(void) {
    fastio;

    long long n;
    cin >> n;

    int cnt = 0;
    int arr[2] = {2, 3};

    while (n != 1) {
        if (n % arr[cnt] != 0) {

            if (cnt) {
                cout << "No" << endl;
                return 0;
            }
            cnt++;
        } else
            n /= arr[cnt];
    }

    cout << "Yes" << endl;

    return 0;
}