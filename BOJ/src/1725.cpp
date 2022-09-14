#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

long long N;
vector<long long> h;

long long box(long long left, long long right)
{
    if(left == right) return h[left];

    long long mid = (left + right) / 2;

    long long ret = max(box(left, mid), box(mid + 1, right));

    long long lo = mid, hi = mid + 1;
    long long height = min(h[lo], h[hi]);

    ret = max(ret, height * 2);

    while (left < lo || hi < right)
    {
        if (hi < right & (lo == left || h[lo - 1] < h[hi + 1]))
        {
            ++hi;
            height = min(height, h[hi]);
        }
        else
        {
            --lo;
            height = min(height, h[lo]);   
        }
        ret = max(ret, (hi - lo + 1) * height);
    }
    
    return ret;
}

void solve()
{
    cin >> N;

    h.resize(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> h[i];
        
    cout << box(1, N) << endl;
}
    

int main()
{
    FastIO;
    
    solve();

    return 0;
}
