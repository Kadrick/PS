/**
 * @file 16566.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief binary search
 * @version 0.1
 * @date 2022-10-13 10:23
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
        parent[min(u, v)] = max(u, v);
        return true;
    }

    return false;
}

int main(void)
{
    fastio;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(m, 0);
    vector<int> numbers(m, 0);
    vector<bool> visit(m, false);
    for (int i = 0; i < m; i++)
    {
        cin >> numbers[i];
        parent[i] = i;
    }
    numbers.push_back(INT_MAX);

    sort(numbers.begin(), numbers.end());

    vector<int> ans;

    while (k--)
    {
        int input;
        cin >> input;

        int pos = upper_bound(numbers.begin(), numbers.end(), input) - numbers.begin();
        pos = findParent(parent, pos);
        ans.push_back(numbers[pos]);
        merge(parent, pos, pos + 1);
    }

    for (auto &&val : ans)
        cout << val << endl;

    return 0;
}