#include <bits/stdc++.h>
#define FastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
using namespace std;

int ans;
string str;

pair<int, int> length(int idx)
{
    int sub_lenght = 0;
    for (int i = idx; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            if(sub_lenght) sub_lenght--;
            pair<int, int> tmp = length(i + 1);
            sub_lenght += (str[i - 1] - '0') * tmp.first;
            i = tmp.second;
            continue;
        }
        else if(str[i] == ')')
        {
            return make_pair(sub_lenght, i);
        }
        else
        {
            sub_lenght++;
        }
    }
    return make_pair(sub_lenght, str.size() - 1);    
}

void solve()
{
    cin >> str;

    cout << length(0).first;
}

int main()
{
    FastIO;

    solve();

    return 0;
}
