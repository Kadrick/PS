#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

typedef vector<vector<bool>> matrix;

int n, m, cnt;
matrix mat1, mat2;

void filp(int r, int c)
{
    for (int i = r; i < r + 3; i++)
    {
        for (int j = c; j < c + 3; j++)
        {
            mat1[i][j] = !mat1[i][j];
        }
    }
    cnt++;
}

void solve()
{
    cin >> n >> m;

    mat1.resize(n, vector<bool>(m));
    mat2.resize(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            mat1[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            mat2[i][j] = str[j] - '0';
        }
    }

    if (mat1 == mat2)
    {
        cout << cnt << endl;
        return;
    }

    for (int i = 0; i < n - 3 + 1; i++)
    {
        for (int j = 0; j < m - 3 + 1; j++)
        {
            if (mat1[i][j] != mat2[i][j])
                filp(i, j);
            if (mat1 == mat2)
            {
                cout << cnt << endl;
                return;
            }
        }
    }
    

    cout << -1 << endl;
}

int main()
{
    FastIO;

    solve();

    return 0;
}
