#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

int main(void) {
  fastio;

  string curTime;
  string startTime;

  cin >> curTime >> startTime;
  int one_day = 60 * 60 * 24;

  int cur_hour = atoi((curTime.substr(0, 2)).c_str());
  int cur_min = atoi((curTime.substr(3, 4)).c_str());
  int cur_sec = atoi((curTime.substr(6, 7)).c_str());

  // cout << cur_hour << cur_min << cur_sec << endl;

  int start_hour = atoi((startTime.substr(0, 2)).c_str());
  int start_min = atoi((startTime.substr(3, 4)).c_str());
  int start_sec = atoi((startTime.substr(6, 7)).c_str());

  // cout << start_hour << start_min << start_sec << endl;

  int finalTimeSec = start_hour * 60 * 60 + start_min * 60 + start_sec;
  int curTimeSec = cur_hour * 60 * 60 + cur_min * 60 + cur_sec;

  // cout << finalTimeSec << ' ' << curTimeSec << endl;
  int ansTimeSec = abs(finalTimeSec - curTimeSec);

  if (finalTimeSec < curTimeSec) {
    ansTimeSec = one_day - ansTimeSec;
  }

  int ansHour = ansTimeSec / 3600;
  ansTimeSec -= ansHour * 3600;
  int ansMin = ansTimeSec / 60;
  ansTimeSec -= ansMin * 60;
  int ansSec = ansTimeSec;

  cout << setw(2) << setfill('0') << ansHour << ":" << setw(2) << setfill('0')
       << ansMin << ":" << setw(2) << setfill('0') << ansSec << endl;

  return 0;
}