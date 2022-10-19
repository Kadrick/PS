/**
 * @file 14440.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math 1h 28m
 * @version 0.1
 * @date 2022-10-19 15:49
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

#define matrix vector<vector<long long>>

matrix operator*(const matrix &left, const matrix &right)
{
    matrix ret(left.size(), vector<long long>(right[0].size(), 0));
    for (int i = 0; i < left.size(); ++i)
    {
        for (int j = 0; j < right[0].size(); ++j)
        {
            for (int k = 0; k < right.size(); ++k)
                ret[i][j] += left[i][k] * right[k][j];
            ret[i][j] = ret[i][j] % 100;
        }
    }
    return ret;
}

matrix pow(matrix m, int n)
{
    if (n == 1)
        return m;

    matrix tmp = pow(m, n / 2);
    if (n % 2)
        return tmp * tmp * m;
    return tmp * tmp;
}

int main(void)
{
    fastio;

    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n;

    matrix mat(2, vector<long long>(2, 0));
    mat[0][0] = x;
    mat[0][1] = y;
    mat[1][0] = 1;

    matrix init(2, vector<long long>(1, 0));
    init[0][0] = a1;
    init[1][0] = a0;

    cout << setw(2) << setfill('0');
    if (n == 0)
        cout << a0 << endl;
    else if (n == 1)
        cout << a1 << endl;
    else
    {
        matrix ans = pow(mat, n - 1) * init;
        cout << ans[0][0] << endl;
    }

    return 0;
}