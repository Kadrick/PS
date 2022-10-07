/**
 * @file 14786.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-10-07 16:51
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

int main(void)
{
    fastio;

    double a, b, c;
    cin >> a >> b >> c;

    // https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=mykepzzang&logNo=220086269649

    // ax + bsin(x) = c
    // a + bcos(x)

    auto origin = [&](double x) -> double
    {
        return a * x + b * sin(x) - c;
    };

    auto differential = [&](double x) -> double
    {
        return a + b * cos(x);
    };

    double param = 1, ans;

    for (int i = 0; i < 1e6; i++)
    {
        ans = param - origin(param) / differential(param);
        param = ans;
    }

    cout << fixed;
    cout.precision(12);
    cout << ans << endl;

    return 0;
}