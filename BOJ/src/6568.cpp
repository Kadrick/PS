/**
 * @file 6568.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement 1h 58m
 * @version 0.1
 * @date 2022-10-24 14:47
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

int bytesToInt(string bytes)
{
    int ret = 0, offset = 1;
    for (int i = 0; i < bytes.size(); i++)
    {
        ret += (bytes[bytes.size() - i - 1] - '0') * offset;
        offset = offset * 2;
    }
    return ret;
}

string intToBytes(int num)
{
    string ret;
    while (num)
    {
        if (num % 2)
            ret.push_back('1');
        else
            ret.push_back('0');
        num /= 2;
    }

    if (ret.size() < 8)
    {
        for (int i = 0; ret.size() < 8; i++)
            ret.push_back('0');
    }
    else if (ret.size() > 8)
    {
        for (int i = 0; ret.size() > 8; i++)
            ret.pop_back();
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main(void)
{
    fastio;

    vector<string> cmd(32, "");

    while (cin >> cmd[0])
    {
        for (int i = 0; i < 31; i++)
            cin >> cmd[i + 1];

        int pc = 0, adder = 0;
        while (1)
        {
            string op = cmd[pc].substr(0, 3);
            string xx = cmd[pc].substr(3, 8);
            pc = (pc + 1) % 32;

            if (op == "111")
                break;
            else if (op == "000")
                cmd[bytesToInt(xx)] = intToBytes(adder);
            else if (op == "001")
                adder = bytesToInt(cmd[bytesToInt(xx)]);
            else if (op == "010")
            {
                if (adder == 0)
                    pc = bytesToInt(xx);
            }
            else if (op == "011")
                continue;
            else if (op == "100")
                adder = (adder - 1 + 256) % 256;
            else if (op == "101")
                adder = (adder + 1) % 256;
            else if (op == "110")
                pc = bytesToInt(xx);
        }

        cout << intToBytes(adder) << endl;
    }

    return 0;
}