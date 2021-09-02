#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

typedef pair<int, int> Point;

int n;
vector<Point> points;

bool comp(Point &left, Point &right) { return left.second < right.second; }

int getDistance(Point &p1, Point &p2) {
  return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

int closestPair(int start, int size) {
  //기저 사례
  if (size == 2)
    return getDistance(points[start], points[start + 1]);
  if (size == 3)
    return min({getDistance(points[start], points[start + 1]),
                getDistance(points[start], points[start + 2]),
                getDistance(points[start + 1], points[start + 2])});

  //중간 기준선과 case 1, 2에서의 거리의 최솟값
  int midLine =
      (points[start + size / 2 - 1].first + points[start + size / 2].first) / 2;
  int d = min(closestPair(start, size / 2),
              closestPair(start + size / 2, size - size / 2));

  //기준선에서 d거리 안의 점들
  vector<Point> midPoint;

  for (int i = start; i < start + size; ++i) {
    int distToMid = midLine - points[i].first;
    if (distToMid * distToMid < d)
      midPoint.push_back(points[i]);
  }

  sort(midPoint.begin(), midPoint.end(), comp);

  int midSize = midPoint.size();
  for (int i = 0; i < midSize - 1; ++i) {
    for (int j = i + 1; j < midSize; ++j) {
      if (pow(midPoint[i].second - midPoint[j].second, 2) >= d)
        break;
      d = min(d, getDistance(midPoint[j], midPoint[i]));
    }
  }

  return d;
}

int main(void) {
  fastio;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    Point point;
    cin >> point.first >> point.second;
    points.push_back(point);
  }

  // x좌표 기준으로 정렬
  sort(points.begin(), points.end());

  cout << closestPair(0, n);

  return 0;
}