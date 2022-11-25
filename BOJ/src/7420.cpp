/**
 * @file 7420.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief geometry
 * @version 0.1
 * @date 2022-11-25 10:25
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

enum DIR
{
    CW,
    CCW,
    STRAIGHT
};

int main(void)
{
    fastio;

    cout << fixed;
    cout.precision(0);

    int N, L;
    cin >> N >> L;

    vector<pair<long long, long long>> points(N);

    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y;

    auto dist = [](const pair<long long, long long> &src,
                   const pair<long long, long long> &dst)
        -> long long
    {
        return (dst.x - src.x) * (dst.x - src.x) + (dst.y - src.y) * (dst.y - src.y);
    };

    auto norm = [](const pair<long long, long long> &vec)
        -> long double
    {
        return sqrt(vec.x * vec.x + vec.y * vec.y);
    };

    auto p2v = [](const pair<long long, long long> &src,
                  const pair<long long, long long> &dst)
        -> pair<long long, long long>
    {
        return {dst.x - src.x, dst.y - src.y};
    };

    auto inner = [](const pair<long long, long long> &baseVec,
                    const pair<long long, long long> &targetVec)
        -> long long
    {
        return baseVec.x * targetVec.x + baseVec.y * targetVec.y;
    };

    auto cross = [](const pair<long long, long long> &baseVec,
                    const pair<long long, long long> &targetVec)
        -> long long
    {
        return baseVec.x * targetVec.y - baseVec.y * targetVec.x;
    };

    auto ccwPos = [&](const pair<long long, long long> &baseStart,
                      const pair<long long, long long> &baseEnd,
                      const pair<long long, long long> &targetStart,
                      const pair<long long, long long> &targetEnd)
        -> int
    {
        pair<long long, long long> baseVec = {baseEnd.x - baseStart.x, baseEnd.y - baseStart.y};
        pair<long long, long long> targetVec = {targetEnd.x - targetStart.x, targetEnd.y - targetStart.y};

        int zVal = cross(baseVec, targetVec);

        if (zVal > 0)
            return DIR::CCW;
        if (zVal == 0)
            return DIR::STRAIGHT;
        return DIR::CW;
    };

    auto ccwVec = [&](const pair<long long, long long> &baseVec,
                      const pair<long long, long long> &targetVec)
        -> int
    {
        int zVal = cross(baseVec, targetVec);

        if (zVal > 0)
            return DIR::CCW;
        if (zVal == 0)
            return DIR::STRAIGHT;
        return DIR::CW;
    };

    auto compYpos = [](
                        const pair<long long, long long> &left,
                        const pair<long long, long long> &right)
        -> bool
    {
        if (left.y == right.y)
            return left.x < right.x;
        return left.y < right.y;
    };

    auto compDeg = [&](
                       const pair<long long, long long> &left,
                       const pair<long long, long long> &right)
        -> bool
    {
        int chk = ccwVec(p2v(points[0], left), p2v(points[0], right));

        if (chk == DIR::STRAIGHT)
            return dist(points[0], left) < dist(points[0], right);
        return chk == DIR::CCW;
    };

    sort(points.begin(), points.end(), compYpos);
    sort(points.begin() + 1, points.end(), compDeg);

    vector<pair<long long, long long>> cvHull;
    cvHull.push_back(points[0]);
    cvHull.push_back(points[1]);

    int last = 2;

    while (last < N)
    {
        while (cvHull.size() >= 2)
        {
            pair<long long, long long> waypoint, src;
            waypoint = cvHull.back(), cvHull.pop_back(), src = cvHull.back();

            if (ccwVec(p2v(src, waypoint), p2v(src, points[last])) == DIR::CCW)
            {
                cvHull.push_back(waypoint);
                break;
            }
        }
        cvHull.push_back(points[last]);
        last++;
    }

    if (cvHull.size() == 2)
    {
        long long straight = dist(cvHull[0], cvHull[1]);
        cout << sqrt(straight) * 2 + 2 * M_PI * L << endl;
        return 0;
    }

    long double ans = 0;
    for (int i = 0; i < cvHull.size(); i++)
    {
        int iNext = (i + 1) % cvHull.size();
        int iNextNext = (i + 2) % cvHull.size();

        long long straight = dist(cvHull[i], cvHull[iNext]);
        ans += sqrt(straight);

        pair<long long, long long> leftVec, rightVec;
        leftVec = p2v(cvHull[iNext], cvHull[i]);
        rightVec = p2v(cvHull[iNext], cvHull[iNextNext]);

        double theta = acos(inner(leftVec, rightVec) / (norm(leftVec) * norm(rightVec)));
        ans += (M_PI - theta) * L;
    }

    cout << ans << endl;

    return 0;
}