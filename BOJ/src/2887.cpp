/**
 * @file 2887.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief kruskal
 * @version 0.1
 * @date 2022-10-07 15:14
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

typedef struct _Point
{
    int X;
    int Y;
    int Z;

    _Point(int x, int y, int z) : X{x}, Y{y}, Z{z} {}
} Point;

int dist(const Point &left, const Point &right)
{
    return min({abs(left.X - right.X), abs(left.Y - right.Y), abs(left.Z - right.Z)});
}

int findParent(vector<int> &parent, int target)
{
    if (parent[target] == target)
        return target;
    return parent[target] = findParent(parent, parent[target]);
}

bool merge(vector<int> &parent, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v)
    {
        parent[max(u, v)] = min(u, v);
        return true;
    }

    return false;
}

int main(void)
{
    fastio;

    int n;
    cin >> n;

    vector<Point> points;
    vector<int> parent(n);
    vector<vector<pair<int, int>>> order(3);
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;

        int x, y, z;
        cin >> x >> y >> z;
        points.push_back(Point(x, y, z));
        order[0].push_back({x, i});
        order[1].push_back({y, i});
        order[2].push_back({z, i});
    }

    for (int i = 0; i < 3; i++)
        sort(order[i].begin(), order[i].end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != n - 1)
            {
                int self = order[j][i].second;
                int neighbor = order[j][i + 1].second;
                edges.push_back({dist(points[self], points[neighbor]), {self, neighbor}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;

    for (auto &&edge : edges)
    {
        if (merge(parent, edge.second.first, edge.second.second))
            ans += edge.first;
    }

    cout << ans << endl;

    return 0;
}