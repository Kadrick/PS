/***********************************
> File Name: 10825.cpp
> Author: Kadrick, BoGwon Kang
> Created Time: 2021/09/27 03:06
> Description: sorting
***********************************/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef struct _Person {
  string name;
  int math;
  int eng;
  int kor;
  _Person(string n, int k, int e, int m) : name(n), math(m), eng(e), kor(k) {}
} Person;

bool comp(const Person &left, const Person &right) {
  // kor
  if (left.kor > right.kor)
    return true;
  if (left.kor < right.kor)
    return false;

  // eng
  if (left.eng < right.eng)
    return true;
  if (left.eng > right.eng)
    return false;

  // math
  if (left.math > right.math)
    return true;
  if (left.math < right.math)
    return false;

  // string
  if (left.name.compare(right.name) < 0)
    return true;
  return false;
}

int n;
vector<Person> people;

int main(void) {
  fastio;

  cin >> n;
  string name;
  int math, kor, eng;
  for (int i = 0; i < n; ++i) {
    cin >> name >> kor >> eng >> math;
    people.push_back(Person(name, kor, eng, math));
  }

  sort(people.begin(), people.end(), comp);

  for (auto &p : people) {
    cout << p.name << endl;
  }

  return 0;
}