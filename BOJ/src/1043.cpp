/**
 * @file 1043.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-10-11 11:19
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

int findParent(vector<int> &parent, int root)
{
    if (root == parent[root])
        return root;
    return parent[root] = findParent(parent, parent[root]);
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

    int n, m, tmp, ans = 0;
    cin >> n >> m;

    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    vector<vector<int>> party;

    cin >> tmp;
    for (int i = 0; i < tmp; i++)
    {
        int id;
        cin >> id;
        parent[id] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int income, id, before;
        cin >> income;
        vector<int> people(income);
        for (int j = 0; j < income; j++)
            cin >> people[j];

        for (int j = 1; j < income; j++)
            merge(parent, people[j - 1], people[j]);

        party.push_back(people);
    }

    for (int i = 0; i < m; i++)
    {
        int participate = 1;
        for (auto &&person : party[i])
        {
            int isKnow = findParent(parent, person);
            if (isKnow == 0)
            {
                participate = 0;
                break;
            }
        }
        ans += participate;
    }

    cout << ans << endl;

    return 0;
}