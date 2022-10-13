/**
 * @file 2733.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-10-12 17:08
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

const int MAXLEN = 32768;
const int MAXVAL = 256;

int main(void)
{
    fastio;

    int t;
    cin >> t;

    for (int id = 0; id < t; id++)
    {
        cout << "PROGRAM #" << id + 1 << ":" << endl;
        string tape;
        vector<string> commands;
        while (true)
        {
            string input;
            getline(cin, input);
            if (input == "end")
                break;

            input.erase(remove(input.begin(), input.end(), ' '), input.end());
            tape += input.substr(0, input.find_first_of('%'));
        }

        vector<int> pointer(40000, 0);
        vector<int> pairPos(40000, -1);

        bool error = false;
        string output;
        int picker = 0;
        stack<int> brace;

        for (int i = 0; i < tape.size(); i++)
        {
            if (tape[i] == '[')
                brace.push(i);
            else if (tape[i] == ']')
            {
                if (brace.empty())
                {
                    error = true;
                    break;
                }

                pairPos[brace.top()] = i;
                pairPos[i] = brace.top();
                brace.pop();
            }
        }

        if (error || !brace.empty())
        {
            cout << "COMPILE ERROR" << endl;
            continue;
        }

        for (int i = 0; i < tape.size(); i++)
        {
            switch (int(tape[i]))
            {
            case '>':
                picker++;
                picker %= MAXLEN;
                break;
            case '<':
                picker--;
                if (picker < 0)
                    picker = MAXLEN - 1;
                break;
            case '+':
                pointer[picker]++;
                pointer[picker] %= MAXVAL;
                break;
            case '-':
                pointer[picker]--;
                if (pointer[picker] < 0)
                    pointer[picker] = MAXVAL - 1;
                break;
            case '.':
                output.push_back(pointer[picker]);
                break;
            case '[':
                if (pointer[picker] == 0)
                    i = pairPos[i] - 1;
                break;
            case ']':
                if (pointer[picker] != 0)
                    i = pairPos[i] - 1;
                break;
            default:
                break;
            }
        }

        cout << output << endl;
    }

    return 0;
}