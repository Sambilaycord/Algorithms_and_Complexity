#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

// Structure to represent a point in 2D space
struct Point {
    double x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Function to find the closest pair of points using a brute-force approach
pair<Point, Point> closestPair(const vector<Point>& points) {
    pair<Point, Point> closest;
    double minDistance = numeric_limits<double>::max();

    // Brute-force approach to find the closest pair
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closest = make_pair(points[i], points[j]);
            }
        }
    }

    return closest;
}

int main() {
    // Example usage
    vector<Point> points = {{2, 3}, {12, 30}, {4, 1}, {7, 16}, {5, 5}};
    
    pair<Point, Point> closest = closestPair(points);
    double dist = distance(closest.first, closest.second);

    cout << "Closest pair: (" << closest.first.x << ", " << closest.first.y << ") and (" 
         << closest.second.x << ", " << closest.second.y << ")" << " with distance: " << dist << endl;

    return 0;
}