/**
 * @file 1891.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Divide & Conquer
 * @version 0.1
 * @date 2023-05-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

pair<long long, long long> findS(string &milestone, int depth, long long left, long long top)
{
    if (milestone.size() == depth)
        return {left, top};

    long long length = (long long)1 << (milestone.size() - depth);

    switch (milestone[depth])
    {
    case '1':
        return findS(milestone, depth + 1, left + length / 2, top);
    case '2':
        return findS(milestone, depth + 1, left, top);
    case '3':
        return findS(milestone, depth + 1, left, top + length / 2);
    case '4':
        return findS(milestone, depth + 1, left + length / 2, top + length / 2);

    default:
        return {-1, -1};
    }
}

string findE(pair<long long, long long> &dest, int depth, long long left, long long top)
{
    if (depth == 0)
    {
        if (dest.first != left || dest.second != top)
            return "-1";
        return "";
    }
    long long unit = (long long)1 << depth;

    bool checkCol = dest.first < left + (unit / 2);
    bool checkRow = dest.second < top + (unit / 2);

    int dir = checkCol ? (checkRow ? 2 : 3) : (checkRow ? 1 : 4);

    switch (dir)
    {
    case 1:
        return "1" + findE(dest, depth - 1, left + unit / 2, top);
    case 2:
        return "2" + findE(dest, depth - 1, left, top);
    case 3:
        return "3" + findE(dest, depth - 1, left, top + unit / 2);
    case 4:
        return "4" + findE(dest, depth - 1, left + unit / 2, top + unit / 2);
    default:
        return "-1";
    }
}

int main(void)
{
    fastio;

    int d;
    string input;
    cin >> d >> input;
    long long mx, my;
    cin >> mx >> my;

    pair<long long, long long> start = findS(input, 0, 0, 0);

    if (start.first == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    start.first += mx;
    start.second -= my;

    string result = findE(start, d, 0, 0);

    if (result[result.size() - 2] == '-')
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}