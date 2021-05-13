#include<iostream>
#include<vector>
#include<queue>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n, m, v;
vector<bool> visited1, visited2;
vector<vector<bool>> adj;

void dfs(int v)
{
	if (!visited1[v])
	{
		cout << v << ' ';
		visited1[v] = true;
		for (int i = 1; i <= n; i++)
		{
			if (adj[v][i])
			{
				dfs(i);
			}
		}
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited2[v] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 1; i <= n; i++)
		{
			if (adj[cur][i] && !visited2[i])
			{
				q.push(i);
				visited2[i] = true;
			}
		}
	}
}

void solve()
{
	cin >> n >> m >> v;
	visited1.resize(n + 1, false);
	visited2.resize(n + 1, false);
	adj.resize(n + 1, vector<bool>(n + 1));
	
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		adj[s][e] = true;
		adj[e][s] = true;
	}

	dfs(v);
	cout << endl;
	bfs(v);
}


int main(void)
{
	fastio;

	solve();

	return 0;
}
