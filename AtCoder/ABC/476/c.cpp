/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
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


    priority_queue<int> pq;


    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        pq.push(-a);
    }

    cout << -pq.top() << endl;

    for (int i = 3; i < n; i++) {
        int a;
        cin >> a;

        if (-pq.top() < a) {
            pq.pop();
            pq.push(-a);
        }


        cout << -pq.top() << endl;
    }

    return 0;
}