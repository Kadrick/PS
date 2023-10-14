/**
 * @file c.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-23 20:58
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

    int k, cnt = 0;
    cin >> k;

    if (k < 10) {
        cout << k << endl;
        return 0;
    }

    priority_queue<long long> pq;
    for (int i = 0; i < 10; i++) {
        pq.push(-i);
    }

    while (true) {

        long long top = -pq.top();
        pq.pop();

        if (k == cnt) {
            cout << top << endl;
            break;
        }

        string tmp = to_string(top);

        for (int i = 1; i <= 9; i++) {
            if ('0' + i > tmp[0]) {

                string a;
                a.push_back('0' + i);

                pq.push(-stoll(a + tmp));
            }
        }

        cnt++;
    }

    return 0;
}