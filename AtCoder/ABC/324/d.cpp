/**
 * @file d.cpp
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

    int n;
    cin >> n;
    string digit;
    cin >> digit;

    sort(digit.begin(), digit.end(),
         [](const char &left, const char &right) -> bool {
             return left > right;
         });
    long long maxV = floor(sqrt(stoll(digit)));

    sort(digit.begin(), digit.end());
    long long minV = ceil(sqrt(stoll(digit)));

    int cnt = 0;

    for (long long i = minV; i <= maxV; i++) {

        string target = to_string((long long)pow(i, 2));
        while (target.length() < n)
            target = "0" + target;

        sort(target.begin(), target.end());
        if (target == digit)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}