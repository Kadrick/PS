#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int n, u, v;
unsigned long long cntG, cntD;
vector<vector<int>> adjList;
vector<pair<int,int>> edge;

int main(void)
{
    fastio

    cin >> n;
    adjList.resize(n + 1, vector<int> ());
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        edge.push_back(make_pair(u, v));
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(auto&& adjNodeArr : adjList) {
        if(adjNodeArr.size() >= 3)
            cntG += (unsigned long long)adjNodeArr.size() * (adjNodeArr.size() - 1)  * (adjNodeArr.size() - 2) / 6;
    }

    for(auto&& e : edge) {
        cntD += (adjList[e.first].size() - 1) *( adjList[e.second].size() - 1);
    }

    if(cntD > cntG * 3) cout << 'D';
    else if(cntD == cntG * 3) cout << "DUDUDUNGA";
    else cout << 'G';

    return 0;
}