/**
 * @file 1025.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Brute force
 * @version 0.1
 * @date 2022-11-21 16:26
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

    int n, m;
    cin >> n >> m;

    auto check = [](int num) -> bool
    {
        int piece = (int)sqrt(num);
        return piece * piece == num;
    };

    int ans = -1;
    vector<string> board;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        board.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int drow = -n; drow < n; drow++)
            {
                for (int dcol = -m; dcol < m; dcol++)
                {
                    if (drow == 0 && dcol == 0)
                        continue;

                    string numbers = "";
                    int y, x;
                    y = i;
                    x = j;

                    for (; 0 <= y && y < n && 0 <= x && x < m;)
                    {
                        numbers += board[y][x];
                        y += drow;
                        x += dcol;

                        if (check(stoi(numbers)))
                            ans = max(ans, stoi(numbers));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}