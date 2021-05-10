#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

int N, blue, white;
vector<vector<int>> board;

void quad(int size, int r, int c)
{
    int flag = board[r][c];
    bool check = false;

    for (int i = r; i < r + size; i++)
    {
        for (int j = c; j < c + size; j++)
        {
            if(flag != board[i][j])
            {
                check = true;
                break;
            }
        }
        if(check)
            break;
    }

    if(check)
    {
        quad(size / 2, r, c);
        quad(size / 2, r, c + size / 2);
        quad(size / 2, r  + size / 2, c);
        quad(size / 2, r + size / 2, c + size / 2);
    }
    else
    {
        if (flag)
            blue++;
        else
            white++;
    }
    
}

void solve()
{
    cin >> N;
    board.resize(N + 1, vector<int>(N + 1));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }

    quad(N, 1, 1);

    cout << white << endl << blue << endl;
}

int main()
{
    FastIO;

    solve();

    return 0;
}
