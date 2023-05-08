/**
 * @file 25636.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief Shortest Path
 * @version 0.1
 * @date 2023-05-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'

struct comp
{
    bool operator()(
        tuple<long long, long long, int> &left,
        tuple<long long, long long, int> &right)
    {
        int leftDist, leftWater, leftCity;
        int rightDist, rightWater, rightCity;

        tie(leftDist, leftWater, leftCity) = left;
        tie(rightDist, rightWater, rightCity) = right;

        if (leftDist == rightDist)
            return leftWater < rightWater;

        return leftDist > rightDist;
    }
};

int main(void)
{
    fastio;

    int n, m;
    cin >> n;

    vector<long long> water(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> water[i + 1];

    cin >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    int start, end;
    cin >> start >> end;

    vector<pair<long long, long long>> cache(n + 1, {LLONG_MAX, 0});

    priority_queue<
        tuple<long long, long long, int>,
        vector<tuple<long long, long long, int>>,
        comp>
        pq;

    pq.push(make_tuple((long long)0, water[start], start));

    while (!pq.empty())
    {
        long long distance, watertank;
        int here;

        tie(distance, watertank, here) = pq.top();
        pq.pop();

        if (
            distance > cache[here].first // 거리가 길거나
            ||
            (distance == cache[here].first && watertank <= cache[here].second) // 물이 같거나 적으면 스킵
        )
            continue;

        cache[here] = {distance, watertank};

        if (here == end)
            continue;

        for (auto &&neighbor : graph[here])
        {
            pq.push(make_tuple(
                neighbor.second + distance,
                water[neighbor.first] + watertank,
                neighbor.first));
        }
    }

    if (cache[end].first == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << cache[end].first << ' ' << cache[end].second << endl;

    return 0;
}