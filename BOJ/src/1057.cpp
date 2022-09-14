#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int main(void)
{
    fastio

    int N, K, I, ans = -1, cnt = 1;

    cin >> N >> K >> I;
    K --;
    I--;
    while (N) {
        
        if (abs(K-I) == 1 && K / 2 == I / 2) {
            ans = cnt;
            break;
        }

        K /= 2;
        I /= 2;
        cnt++;
        N /= 2;
    }

    cout << ans;
    return 0;
}