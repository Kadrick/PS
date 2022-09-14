/**
 * @file 2251.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-09-14 14:33
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

    int a, b, c;
    cin >> a >> b >> c;

    set<int> ans;
    map<tuple<int, int, int>, bool> visitState;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, c));
    visitState[make_tuple(0, 0, c)] = true;

    while (!q.empty())
    {
        int nxtA, nxtB, nxtC, curA, curB, curC;
        tie(curA, curB, curC) = q.front();
        q.pop();

        if (curA == 0)
            ans.insert(curC);

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // c to b
        if (nxtC != 0 && nxtB < b)
        {
            int sum = nxtB + nxtC;
            nxtB = min(b, sum);
            nxtC = sum - nxtB;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // c to a
        if (nxtC != 0 && nxtA < a)
        {
            int sum = nxtA + nxtC;
            nxtA = min(a, sum);
            nxtC = sum - nxtA;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // a to b
        if (nxtA != 0 && nxtB < b)
        {
            int sum = nxtB + nxtA;
            nxtB = min(b, sum);
            nxtA = sum - nxtB;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // a to c
        if (nxtA != 0 && nxtC < c)
        {
            int sum = nxtA + nxtC;
            nxtC = min(c, sum);
            nxtA = sum - nxtC;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // b to a
        if (nxtC != 0 && nxtA < a)
        {
            int sum = nxtB + nxtA;
            nxtA = min(a, sum);
            nxtB = sum - nxtA;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }

        nxtA = curA;
        nxtB = curB;
        nxtC = curC;
        // b to c
        if (nxtB != 0 && nxtC < c)
        {
            int sum = nxtB + nxtC;
            nxtC = min(c, sum);
            nxtB = sum - nxtC;

            tuple<int, int, int> bucket = make_tuple(nxtA, nxtB, nxtC);
            if (visitState.find(bucket) == visitState.end())
            {
                q.push(bucket);
                visitState[bucket] = true;
            }
        }
    }

    for (auto iter = ans.begin(); iter != ans.end(); iter++)
        cout << *iter << ' ';
    cout << endl;

    return 0;
}