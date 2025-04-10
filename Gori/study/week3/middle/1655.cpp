/**
 * @file 1655.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 16:06
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int32_t main(int argc, char **argv) {
    fastio;

    priority_queue<int, vector<int>, less<int>> Apq;
    priority_queue<int, vector<int>, greater<int>> Bpq;

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (Apq.size() == Bpq.size()) {
            Apq.push(x);
        } else {
            Bpq.push(x);
        }

        if (Apq.size() != 0 && Bpq.size() != 0 && Apq.top() > Bpq.top()) {
            int temp1 = Apq.top();
            int temp2 = Bpq.top();
            Apq.pop();
            Bpq.pop();
            Apq.push(temp2);
            Bpq.push(temp1);
        }

        cout << Apq.top() << '\n';
    }

    return 0;
}