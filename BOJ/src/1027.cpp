/**
 * @file 1027.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief ccw 56m
 * @version 0.1
 * @date 2022-11-22 09:04
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

#define y first
#define x second
#define src first
#define dest second
#define point pair<long long, long long>
#define line pair<point, point>

int ccw(point p1, point p2, point p3)
{
    long long a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    long long b = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    long long ret = a - b;
    if (ret < 0)
        return -1;
    if (ret == 0)
        return 0;
    return 1;
}

bool cross(line a, line b)
{
    int atob = ccw(a.src, a.dest, b.src) * ccw(a.src, a.dest, b.dest);
    int btoa = ccw(b.src, b.dest, a.src) * ccw(b.src, b.dest, a.dest);

    if (atob == 0 && atob == btoa)
    {
        bool xpos = (min({a.src.x, a.dest.x}) <= min({b.src.x, b.dest.x}) &&
                     min({b.src.x, b.dest.x}) <= max({a.src.x, a.dest.x})) ||
                    (min({b.src.x, b.dest.x}) <= min({a.src.x, a.dest.x}) &&
                     min({a.src.x, a.dest.x}) <= max({b.src.x, b.dest.x}));
        bool ypos = (min({a.src.y, a.dest.y}) <= min({b.src.y, b.dest.y}) &&
                     min({b.src.y, b.dest.y}) <= max({a.src.y, a.dest.y})) ||
                    (min({b.src.y, b.dest.y}) <= min({a.src.y, a.dest.y}) &&
                     min({a.src.y, a.dest.y}) <= max({b.src.y, b.dest.y}));

        return xpos && ypos;
    }

    return atob <= 0 && btoa <= 0;
}
int main(void)
{
    fastio;

    int n;
    cin >> n;

    vector<long long> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int ans = 0;

    for (int mid = 0; mid < n; mid++)
    {
        int cnt = 0;
        long long pivot = height[mid];
        pair<long long, long long> A, B, C;
        // left
        for (int left = mid - 1; left >= 0; left--)
        {
            bool find = false;
            for (int comp = mid - 1; comp > left; comp--)
            {
                if (cross({{mid, height[mid]}, {left, height[left]}}, {{comp, height[comp]}, {comp, 0}}))
                {
                    find = true;
                    break;
                }
            }

            if (!find)
                cnt++;
        }
        pivot = height[mid];
        // right
        for (int right = mid + 1; right < n; right++)
        {
            bool find = false;
            for (int comp = mid + 1; comp < right; comp++)
            {
                if (cross({{mid, height[mid]}, {right, height[right]}}, {{comp, height[comp]}, {comp, 0}}))
                {
                    find = true;
                    break;
                }
            }

            if (!find)
                cnt++;
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}