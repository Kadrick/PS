#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int N;
vector<int> num;
int ans;

int main(void)
{
    fastio

    cin >> N;
    num.resize(N);
    for (int i = 0; i < N; ++i) 
        cin >> num[i];
    
    sort(num.begin(), num.end());
    do {
        int sum = 0;
        for (int i = 1; i < N; ++i)
            sum += abs(num[i - 1] - num[i]);
        ans = max(ans, sum);
    }while (next_permutation(num.begin(), num.end()));
    
    cout << ans << endl;

    return 0;
}