#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int N,K;
int w[101];
int v[101];
int dp[100001];

int main(void)
{
    fastio
    
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> w[i + 1] >> v[i + 1];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = K; j >= 1; --j) {
            if(w[i] <= j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    
    cout << dp[K];
    
    return 0;
}