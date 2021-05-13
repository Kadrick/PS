#include<iostream>
#include<vector>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int r, c, ans;
vector<vector<char>> board;
vector<bool> visited;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void path(int y, int x, int cnt)
{
	ans = max(cnt, ans);
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (my < 0 || my > r - 1 || mx < 0 || mx > c - 1)
			continue;

		if (!visited[board[my][mx] - 'A'])
		{
			visited[board[my][mx] - 'A'] = true;
			path(my, mx, cnt + 1);
			visited[board[my][mx] - 'A'] = false;
		}
	}
}

void solve()
{
	cin >> r >> c;
	visited.resize(26, false);
	board.resize(r, vector<char>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	visited[board[0][0] - 'A'] = true;
	path(0, 0, 1);

	cout << ans;
}


int main(void)
{
	fastio;

	solve();

	return 0;
}
