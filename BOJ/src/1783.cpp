#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0);
#define endl    '\n'
using namespace std;

int m, n;

void solve()
{
    cin >> n >> m;

    if(n == 1)
        cout << 1 << endl;
    else if(n == 2)
        cout << min(4, (m + 1) / 2) << endl;
    else if(n >= 3)
    {
        if(m <= 6)
            cout << min(m, 4) << endl;
        else
            cout << m - 2 << endl;
    }
}

int main () 
{
    FastIO;

    solve();

    return 0;
}
