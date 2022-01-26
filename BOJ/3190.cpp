/**
 * @file 3190.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-01-27 02:11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int n, k, l, ans;

// clockwise
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<bool>> apple;
deque<pair<int, int>> snake;
map<int, char> rotate_info;

int main(void)
{
  fastio;

  cin >> n >> k;
  apple.resize(n, vector<bool>(n, false));
  for (int i = 0; i < k; i++)
  {
    int r, c;
    cin >> r >> c;
    apple[r - 1][c - 1] = true;
  }

  cin >> l;
  for (int i = 0; i < l; i++)
  {
    int x;
    char dir;
    cin >> x >> dir;
    rotate_info[x] = dir;
  }

  snake.push_front({0, 0});

  int dir = 1;

  while (true)
  {
    ans++;

    int ny = snake.front().first + dy[dir];
    int nx = snake.front().second + dx[dir];

    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
      break;

    bool body_check = false;
    for (auto &&body : snake)
    {
      if (body.first == ny && body.second == nx)
      {
        body_check = true;
        break;
      }
    }
    if (body_check)
      break;

    snake.push_front({ny, nx});

    if (apple[ny][nx])
      apple[ny][nx] = false;
    else
      snake.pop_back();

    if (rotate_info.find(ans) != rotate_info.end())
    {
      if (rotate_info[ans] == 'D')
        dir = (dir + 1) % 4;
      else
        dir = (dir - 1) < 0 ? 3 : dir - 1;
    }
  }

  cout << ans << endl;

  return 0;
}