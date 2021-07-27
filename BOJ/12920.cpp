#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int N, M;
int w[10001];
int v[10001];
int k[10001];
int dp[10001];

int main(void)
{
    fastio
    
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> w[i + 1] >> v[i + 1] >> k[i + 1];
    }

    int cnt = N + 1;

    for (int i = 1; i <= N; ++i) {
        if(k[i] >= 2) {
            k[i] -= 1; //한개짜리는 들어가 있으니까
            while (k[i]) {
                if (k[i] % 2) {
                    w[cnt] = (k[i]/2+1) * w[i];
                    v[cnt] = (k[i]/2+1) * v[i];
                } else {
                   w[cnt] = (k[i]/2) * w[i];
                    v[cnt] = (k[i]/2) * v[i];
                }
                cnt++;
                k[i] /= 2;
            }
        }
    }

    for (int i = 1; i <= cnt - 1; ++i) {
        for (int j = M; j >= 1; --j) {
            if(w[i] <= j) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    
    cout << dp[M];
    
    return 0;
}