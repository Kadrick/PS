/**
 * @file 11559.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief simulation
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<string> board;
bool isVisited[12][6];

auto check_range = [](int y, int x)
{ return 0 <= x && x < 6 && 0 <= y && y < 12; };

bool bfs(int y, int x, char target)
{
  int cnt = 0;

  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();

    cnt++;

    if (cnt >= 4)
      return true;

    for (int i = 0; i < 4; i++)
    {
      int my = here.first + dy[i];
      int mx = here.second + dx[i];

      if (!check_range(my, mx))
        continue;
      if (board[my][mx] != target)
        continue;
      if (isVisited[my][mx])
        continue;
      isVisited[my][mx] = true;
      q.push({my, mx});
    }
  }

  return false;
}

void fill(int y, int x, char target)
{
  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;

  while (!q.empty())
  {
    auto here = q.front();
    q.pop();
    board[here.first][here.second] = '.';

    for (int i = 0; i < 4; i++)
    {
      int my = here.first + dy[i];
      int mx = here.second + dx[i];

      if (!check_range(my, mx))
        continue;
      if (board[my][mx] != target)
        continue;
      if (isVisited[my][mx])
        continue;
      isVisited[my][mx] = true;
      q.push({my, mx});
    }
  }
}

bool check_board()
{
  bool ret = false;
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.' && !isVisited[i][j])
      {
        ret = bfs(i, j, board[i][j]);
        if (ret)
          return true;
      }
    }
  }
  return false;
}

void pop()
{
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (board[i][j] != '.' && !isVisited[i][j])
      {
        if (bfs(i, j, board[i][j]))
        {
          memset(isVisited, false, sizeof(isVisited));
          fill(i, j, board[i][j]);
        }
      }
    }
  }
}

void down()
{
  for (int i = 0; i < 6; i++)
  {
    vector<char> vline;
    for (int j = 0; j < 12; j++)
    {
      if (board[j][i] != '.')
        vline.push_back(board[j][i]);
    }
    for (int j = 11; j >= 0; j--)
    {
      if (!vline.empty())
      {
        board[j][i] = vline.back();
        vline.pop_back();
      }
      else
        board[j][i] = '.';
    }
  }
}

void print_board()
{
  for (int i = 0; i < 12; i++)
  {
    for (int j = 0; j < 6; j++)
      cout << board[i][j];
    cout << endl;
  }
}

int main(void)
{
  fastio;

  /* input */
  for (int i = 0; i < 12; i++)
  {
    string input;
    cin >> input;
    board.push_back(input);
  }

  int chain = 0;
  while (check_board())
  {
    chain++;
    memset(isVisited, false, sizeof(isVisited));
    pop(); // puyo pop
    // print_board();
    memset(isVisited, false, sizeof(isVisited));
    down(); // puyo down
    // print_board();
  }

  cout << chain << endl;

  return 0;
}