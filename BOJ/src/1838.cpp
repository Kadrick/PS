#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

int N, ans;
vector<pair<int, int>> A;

void solve()
{
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, A[i].second - i);
    }
    
    cout << ans;
}

int main()
{
    FastIO;

    solve();

    return 0;
}
