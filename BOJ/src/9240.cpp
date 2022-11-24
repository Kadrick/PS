/**
 * @file 9240.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief geometry
 * @version 0.1
 * @date 2022-11-24 16:24
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
vector<point> points;

int dist(const point &a, const point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int ccw(const point &left, const point &right)
{
    int zVal = left.x * right.y - left.y * right.x;

    if (zVal < 0)
        return DIR::CW;

    if (zVal == 0)
        return DIR::STRAIGHT;

    if (zVal > 0)
        return DIR::CCW;
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

bool comp(const point &left, const point &right)
{
    if (left == pivot)
        return true;
    if (right == pivot)
        return false;

    if (ccw(pivot, left, right) == DIR::STRAIGHT)
        return dist(pivot, left) < dist(pivot, right);

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

    cout << fixed;
    cout.precision(10);

    int N;
    cin >> N;
    points.resize(N);
    pivot.y = LLONG_MAX;

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;

        // pivot
        if (pivot.y > points[i].y)
            pivot = points[i];
        else if (pivot.y == points[i].y && pivot.x > points[i].x)
            pivot = points[i];
    }

    // sorting by rad
    sort(points.begin(), points.end(), comp);

    vector<int> st;
    st.push_back(0);
    st.push_back(1);

    int target = 2;

    while (target < N)
    {
        while (st.size() >= 2)
        {
            int src, waypoint;
            waypoint = st.back(), st.pop_back(), src = st.back();
            if (ccw(points[src], points[waypoint], points[target]) == DIR::CCW)
            {
                st.push_back(waypoint);
                break;
            }
        }

        st.push_back(target);
        target++;
    }

    if (st.size() == 2)
    {
        cout << sqrt(dist(points[st[1]], points[st[0]])) << endl;
        return 0;
    }

    // rotating calipers
    vector<point> convexHull;

    for (int i = 0; i < st.size(); i++)
        convexHull.push_back(points[st[i]]);

    int left = min_element(convexHull.begin(), convexHull.end()) - convexHull.begin();
    int right = max_element(convexHull.begin(), convexHull.end()) - convexHull.begin();

    int maximum = 0;
    pair<int, int> ans = {};

    for (int i = 0; i < convexHull.size(); i++)
    {
        point ls = convexHull[left], le = convexHull[(left + 1) % convexHull.size()];
        point rs = convexHull[right], re = convexHull[(right + 1) % convexHull.size()];

        int now = dist(ls, rs);
        maximum = max(maximum, now);

        if (ccw(
                {le.x - ls.x, le.y - ls.y},
                {rs.x - re.x, rs.y - re.y}) == DIR::CCW)
            left = (left + 1) % convexHull.size();
        else
            right = (right + 1) % convexHull.size();
    }

    cout << sqrt(maximum) << endl;

    return 0;
}