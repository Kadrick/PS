/**
 * @file 4882.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Stack
 * @version 0.1
 * @date 2023-05-02
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

int main(void)
{
    fastio;

    int count = 1;
    string input;

    while (true)
    {
        cin >> input;

        if (input == "()")
            break;

        // logical: true => and, false => or
        bool result = true, logical = true;

        int currentLV = 0;

        vector<pair<int, bool>> st;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '(')
                currentLV++;
            else if (input[i] == ')')
            {
                while (!st.empty() && st.back().first == currentLV)
                {
                    if (logical)
                        result = result && st.back().second;
                    else
                        result = result || st.back().second;
                    st.pop_back();
                }
                currentLV--;
                logical = !logical;
            }
            else
                st.push_back({currentLV, input[i] == 'T' ? true : false});
        }

        cout << count++ << ". " << (result ? "true" : "false") << endl;
    }

    return 0;
}