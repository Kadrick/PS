#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

int N;
vector<vector<char>> board;

string quad(int size, int r, int c)
{
    char flag = board[r][c];
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

    string ret = "";
    if(check)
    {
        ret += "(";
        ret += quad(size / 2, r, c);
        ret += quad(size / 2, r, c + size / 2);
        ret += quad(size / 2, r  + size / 2, c);
        ret += quad(size / 2, r + size / 2, c + size / 2);
        ret += ")";
    }
    else
    {
        ret.push_back(flag);
    }

    return ret;
}

void solve()
{
    cin >> N;
    board.resize(N + 1, vector<char>(N + 1));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    }
    
    string ans = quad(N, 1, 1);

    cout << ans << endl;
}

int main()
{
    FastIO;

    solve();

    return 0;
}
