//author : kadrick
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int n, s;
int arr[40];
vector<int> sum1, sum2;
long long ans;

void dfs1(int idx, int sum) {
  sum += arr[idx]; //0을 세지 않게 주의
  if(idx >= n / 2) return;
  if(sum == s) ans++; //구간 1의 원소로 s를 만들 수 있을 때
  sum1.push_back(sum);
  dfs1(idx + 1, sum - arr[idx]);
  dfs1(idx + 1, sum);
}

void dfs2(int idx, int sum) {
  sum += arr[idx];
  if(idx >= n) return;
  if(sum == s) ans++; //구간 2의 원소로 s를 만들 수 있을 때
  sum2.push_back(sum);
  dfs2(idx + 1, sum - arr[idx]);
  dfs2(idx + 1, sum);
}

int main(void) {
  fastio;

  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  dfs1(0,0);
  dfs2(n / 2,0);

  sort(sum1.begin(), sum1.end());
  sort(sum2.begin(), sum2.end());

  for (int i = 0; i < sum2.size(); ++i) {
    //합쳐서 s로 만들 수 있을때
    int target = s - sum2[i];
    int up = upper_bound(sum1.begin(), sum1.end(), target) - sum1.begin();
    int down = lower_bound(sum1.begin(), sum1.end(), target) - sum1.begin();
    ans += up - down;
  }

  cout << ans;

  return 0;
}