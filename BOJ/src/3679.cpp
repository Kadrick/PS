/**
 * @file 3679.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief geometry
 * @version 0.1
 * @date 2022-11-23 14:02
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

#define x first
#define y second
#define int long long
#define point pair<long long, long long>

enum DIR
{
    CW,
    STRAIGHT,
    CCW
};

int N;
point pivot = {0, 50000};
vector<pair<int, point>> points;

int dist(const point &a, const point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int ccw(const point &src, const point &waypoint, const point &dst)
{
    pair<int, int> srcDstVec = {dst.x - src.x, dst.y - src.y};
    pair<int, int> srcWayVec = {waypoint.x - src.x, waypoint.y - src.y};

    int zVal = srcWayVec.x * srcDstVec.y - srcWayVec.y * srcDstVec.x;

    if (zVal < 0)
        return DIR::CW;

    if (zVal == 0)
        return DIR::STRAIGHT;

    if (zVal > 0)
        return DIR::CCW;
}

bool comp(const pair<int, point> &leftPair, const pair<int, point> &rightPair)
{
    point left = leftPair.second;
    point right = rightPair.second;

    if (left == pivot)
        return true;
    if (right == pivot)
        return false;

    if (ccw(pivot, left, right) == DIR::STRAIGHT)
        return dist(pivot, left) > dist(pivot, right);

    double leftRad = atan2(left.y - pivot.y, left.x - pivot.x);
    double rightRad = atan2(right.y - pivot.y, right.x - pivot.x);

    if (leftRad < 0)
        leftRad = 2 * M_PI + leftRad;

    if (rightRad < 0)
        rightRad = 2 * M_PI + rightRad;

    return leftRad < rightRad;
}

int32_t main(void)
{
    fastio;

    int tc;
    cin >> tc;
    while (tc--)
    {
        /* code */
        cin >> N;

        pivot.y = 50000;
        points.resize(N);
        for (int i = 0; i < N; i++)
        {
            points[i].first = i;
            cin >> points[i].second.x >> points[i].second.y;

            // pivot
            if (pivot.y > points[i].second.y)
                pivot = points[i].second;
            else if (pivot.y == points[i].second.y && pivot.x > points[i].second.x)
                pivot = points[i].second;
        }

        // sorting by rad
        sort(points.begin(), points.end(), comp);

        int start = 0;
        while (start + 2 < N)
        {
            if (ccw(points[start].second,
                    points[start + 1].second,
                    points[start + 2].second) == DIR::STRAIGHT)
                start++;
            else
                break;
        }

        reverse(points.begin() + 1, points.begin() + start + 2);

        for (int i = 0; i < points.size(); i++)
            cout << points[i].first << ' ';
        cout << endl;
    }

    return 0;
}