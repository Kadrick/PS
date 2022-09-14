/**
 * @file 2653.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-05-27 09:08
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

int n;
int belong[100];
int relation[100][100];
vector<vector<int>> ans;

int main(void)
{
  fastio;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    belong[i] = -1;
    for (int j = 0; j < n; j++)
      cin >> relation[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    if (belong[i] != -1)
    {
      int groupID = belong[i];

      vector<int> comp;
      comp.push_back(i);
      for (int j = 0; j < n; j++)
      {
        if (relation[i][j] == 0 && i != j)
          comp.push_back(j);
      }

      sort(comp.begin(), comp.end());

      if (ans[groupID] != comp)
      {
        cout << 0 << endl;
        return 0;
      }
    }
    else
    {
      vector<int> group;

      group.push_back(i);
      for (int j = 0; j < n; j++)
      {
        if (relation[i][j] == 0 && i != j)
        {
          if (belong[j] == -1)
            group.push_back(j);
          else
          {
            cout << 0 << endl;
            return 0;
          }
        }
      }

      if (group.size() == 1)
      {
        cout << 0 << endl;
        return 0;
      }

      sort(group.begin(), group.end());
      ans.push_back(group);

      for (int i = 0; i < group.size(); i++)
        belong[group[i]] = ans.size() - 1;
    }
  }

  sort(ans.begin(), ans.end(),
       [](vector<int> &left, vector<int> &right) -> bool
       {
         return left[0] < right[0];
       });

  cout << ans.size() << endl;
  for (auto &&v : ans)
  {
    for (auto &&num : v)
      cout << num + 1 << ' ';
    cout << endl;
  }

  return 0;
}