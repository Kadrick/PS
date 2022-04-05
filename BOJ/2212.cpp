  /**
   * @file 2212.cpp
   * @author kadrick (kbk2581553@gmail.com)
   * @brief greedy
   * @version 0.1
   * @date 2022-04-05
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

  int main(void)
  {
    fastio;

    int n, k;
    vector<int> arr;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      int tmp;
      cin >> tmp;
      arr.push_back(tmp);
    }

    if (k >= n)
    {
      cout << 0 << endl;
      return 0;
    }

    sort(arr.begin(), arr.end());

    int tmp = arr[0];
    vector<int> dist;
    for (int i = 1; i < n; i++)
    {
      dist.push_back(arr[i] - tmp);
      tmp = arr[i];
    }

    sort(dist.begin(), dist.end());

    int ans = 0;
    for (int i = 0; i < n - k; i++)
      ans += dist[i];

    cout << ans << endl;

    return 0;
  }