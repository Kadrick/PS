#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

int n, u, v;
unsigned long long cntG, cntD;
vector<int> adjList;
vector<pair<int,int>> edge;

int main(void)
{
    fastio

    cin >> n;
    adjList.resize(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        edge.push_back(make_pair(u, v));
        adjList[u]++;
        adjList[v]++;
    }

    for(auto&& adjNode : adjList) {
        if(adjNode >= 3)
            cntG += (unsigned long long)adjNode * (adjNode - 1)  * (adjNode - 2) / 6;
    }

    for(auto&& e : edge) {
        cntD += (adjList[e.first] - 1) *( adjList[e.second] - 1);
    }

    if(cntD > cntG * 3) cout << 'D';
    else if(cntD == cntG * 3) cout << "DUDUDUNGA";
    else cout << 'G';

    return 0;
}