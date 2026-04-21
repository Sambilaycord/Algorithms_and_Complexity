#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}

  // Comparison for sorting by x-coordinate
  bool operator<(const Point& other) const {
    return (x < other.x) || (x == other.x && y < other.y);
  }

  // Static method for cross product
  static int crossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
  }
};

vector<Point> computeConvexHull(vector<Point>& points) {
  vector<Point> hull;

  // Sort points by x-coordinate
  sort(points.begin(), points.end());

  // Compute upper hull
  for (int i = 0; i < points.size(); i++) {
    while (hull.size() >= 2 && Point::crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }

  // Compute lower hull (reuse hull vector)
  int lowerHullIndex = hull.size();
  for (int i = points.size() - 2; i >= 0; i--) {
    while (hull.size() >= lowerHullIndex && Point::crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }

  // Remove last point (duplicate of the first point)
  hull.pop_back();

  return hull;
}

int main() {
  vector<Point> points = {
      {1, 1}, {4, 6}, {8, 2}, {5, 4}, {2, 3}};

  vector<Point> hull = computeConvexHull(points);

  cout << "Given points: ";
  for (const Point& p : points) {
    cout << "(" << p.x << ", " << p.y << "), ";
  }
  cout << "\n";

  cout << "Convex Hull: ";
  for (const Point& p : hull) {
    cout << "(" << p.x << ", " << p.y << "), ";
  }
  cout << "\n";

  return 0;
}
