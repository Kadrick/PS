#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int N;
vector<char> order;
vector<bool> isUse;
vector<string> ans;

bool judge(int left, int right, char op)
{
    if(op == '<') return left < right;
    else return left > right;
}

void solve(int idx_op, string& num)
{
    if (num.size() == N + 1)
    {
        ans.push_back(num);
        return;
    }

    for (int i = 0; i < 10; ++i) 
    {
        if(!isUse[i] && judge(num.back() - '0', i, order[idx_op]))
        {
            isUse[i] = true;
            num.push_back(i + '0');
            solve(idx_op + 1, num);
            num.pop_back();
            isUse[i] = false;
        }
    }

}

int main(void)
{
    fastio
    
    cin >> N;
    order.resize(N);
    isUse.resize(10, false);

    for (int i = 0; i < N; ++i) 
        cin >> order[i];

    string str = "";
    for (int i = 0; i < 10; ++i) 
    {
        isUse[i] = true;
        str.push_back(i + '0');
        solve(0, str);
        str.pop_back();
        isUse[i] = false;
    }

    sort(ans.begin(), ans.end());

    cout << ans[ans.size() - 1] << endl;
    cout << ans[0] << endl;

    return 0;
}