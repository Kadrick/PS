#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef struct Date {
  int year;
  int month;
  int day;
} date;

bool isOld(date person1, date person2) {
  if (person1.year > person2.year)
    return false;
  else if (person1.year < person2.year)
    return true;
  if (person1.month > person2.month)
    return false;
  else if (person1.month < person2.month)
    return true;
  if (person1.day > person2.day)
    return false;
  else if (person1.day < person2.day)
    return true;

  return true;
}

int main(void) {
  fastio;
  int n;
  cin >> n;

  string maxname, minname;
  date maxdate, mindate;
  string input;
  int y, m, d;
  cin >> input >> d >> m >> y;

  maxname = minname = input;
  maxdate.year = mindate.year = y;
  maxdate.month = mindate.month = m;
  maxdate.day = mindate.day = d;

  for (int i = 1; i < n; ++i) {
    cin >> input >> d >> m >> y;
    if (!isOld(maxdate, {y, m, d})) {
      maxdate = {y, m, d};
      maxname = input;
    }
    if (isOld(mindate, {y, m, d})) {
      mindate = {y, m, d};
      minname = input;
    }
  }

  cout << minname << endl << maxname << endl;

  return 0;
}