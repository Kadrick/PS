/**
 * @file 1036.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief string, greedy
 * @version 0.1
 * @date 2022-09-05 10:26
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

typedef string bigInt;

// true => >
// false => <
bool compBigInt(const bigInt &left, const bigInt &right)
{
    if (left.length() == right.length())
    {
        for (int i = 0; i < left.length(); i++)
        {
            if (left[i] == right[i])
                continue;

            return left[i] > right[i];
        }
    }

    return left.length() > right.length();
}

bigInt addBigInt(bigInt left, bigInt right)
{
    bigInt ret = "";

    int total = 0;
    if (left.length() < right.length())
    {
        int paddingLen = right.length() - left.length();
        bigInt padding = bigInt(paddingLen, '0');
        right = "0" + right;
        left = "0" + padding + left;
    }
    else
    {
        int paddingLen = left.length() - right.length();
        bigInt padding = bigInt(paddingLen, '0');
        left = "0" + left;
        right = "0" + padding + right;
    }

    int tmp = 0, sum = 0;
    for (int i = left.length() - 1; i >= 0; i--)
    {
        int lval = 0;
        if ('0' <= left[i] && left[i] <= '9')
            lval = left[i] - '0';
        else
            lval = left[i] - 'A' + 10;

        int rval = 0;
        if ('0' <= right[i] && right[i] <= '9')
            rval = right[i] - '0';
        else
            rval = right[i] - 'A' + 10;

        sum = lval + rval + tmp;
        tmp = sum / 36;
        char add = (sum % 36) < 10 ? char(sum % 36 + '0') : char(sum % 36 - 10 + 'A');
        ret = add + ret;
    }

    while (ret[0] == '0')
        ret = ret.substr(1, ret.length() - 1);

    if (ret.length() == 0)
        ret = "0";

    return ret;
}

int main(void)
{
    fastio;

    int tot, change;
    bigInt ans = "0";
    cin >> tot;

    vector<bigInt> changeVal(36, "0");
    for (int i = 0; i < tot; i++)
    {
        string input = "", base = "";
        cin >> input;
        for (int j = input.length() - 1; j >= 0; j--)
        {
            int idx = 0;

            if ('0' <= input[j] && input[j] <= '9')
                idx = input[j] - '0';
            else
                idx = input[j] - 'A' + 10;

            int addVal = 35 - idx;
            char prefix = addVal < 10 ? char(addVal + '0') : char(addVal - 10 + 'A');

            changeVal[idx] = addBigInt(changeVal[idx], prefix + base);
            base += "0";
        }
        ans = addBigInt(ans, input);
    }
    cin >> change;

    sort(changeVal.begin(), changeVal.end(), compBigInt);

    for (int i = 0; i < change; i++)
        ans = addBigInt(ans, changeVal[i]);

    cout << ans << endl;

    return 0;
}