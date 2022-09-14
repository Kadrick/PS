#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int MOD;

// a를 b제곱한 값을 return 합니다.
long long p(long long a, long long b)
{
    if(b == 1) return a;

    if(b % 2)
        return (p(a, b-1) * a) % MOD; 
    
    long long half = p(a, b/2) % MOD;
    return (half*half) % MOD;
}


int main(void)
{
    fastio

    int a, b, c;
    
    cin >> a >> b >> c;
    MOD = c;
    cout << p(a, b) % MOD;

    return 0;
}