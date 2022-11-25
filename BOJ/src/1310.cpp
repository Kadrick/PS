/**
 * @file 1310.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief geometry
 * @version 0.1
 * @date 2022-11-25 14:18
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

    int N;
    cin >> N;

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
        if (left.x == right.x)
            return left.y < right.y;
        return left.x < right.x;
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

    stable_sort(points.begin(), points.end(), compYpos);
    stable_sort(points.begin() + 1, points.end(), compDeg);

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
        cout << dist(cvHull[0], cvHull[1]) << endl;
        return 0;
    }

    int left = min_element(cvHull.begin(), cvHull.end()) - cvHull.begin();
    int right = max_element(cvHull.begin(), cvHull.end()) - cvHull.begin();

    long long maximum = 0;

    for (int i = 0; i < cvHull.size(); i++)
    {
        long long distance = dist(cvHull[left], cvHull[right]);
        if (distance > maximum)
            maximum = distance;

        int leftNext = (left + 1) % cvHull.size();
        int rightNext = (right + 1) % cvHull.size();

        pair<long long, long long> leftVec, rightVec;
        leftVec = p2v(cvHull[left], cvHull[leftNext]);
        rightVec = p2v(cvHull[right], cvHull[rightNext]);

        int chk = ccwVec(leftVec, rightVec);
        if (chk == DIR::CCW)
            right = rightNext;
        else if (chk == DIR::CW)
            left = leftNext;
        else
        {
            right = rightNext;
            left = leftNext;
        }
    }

    cout << maximum << endl;

    return 0;
}