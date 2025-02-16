#include <bits/stdc++.h>
using namespace std;

// Structure to represent a point
struct Point
{
    double x, y;
    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Function to calculate the cross product of two vectors OA and OB
double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Function to calculate the area of the polygon using the shoelace formula
double polygonArea(const vector<Point> &polygon)
{
    if (polygon.size() < 3)
        return 0; // Not enough points for a polygon
    double area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += polygon[i].x * polygon[j].y;
        area -= polygon[j].x * polygon[i].y;
    }
    return abs(area) / 2.0;
}

// Function to find the convex hull using the Andrew's monotone chain algorithm
vector<Point> convexHull(vector<Point> &points)
{
    sort(points.begin(), points.end());

    vector<Point> lower, upper;

    // Build the lower hull
    for (const Point &p : points)
    {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }

    // Build the upper hull
    for (int i = points.size() - 1; i >= 0; i--)
    {
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) <= 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }

    // Remove the last point of each half because it's repeated at the beginning of the other half
    lower.pop_back();
    upper.pop_back();

    // Concatenate the lower and upper hull to form the convex hull
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

// Function to check if two line segments intersect and find the intersection point
bool getIntersection(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4, pair<double, double> &intersection)
{
    // Line 1: (x1, y1) -> (x2, y2)
    // Line 2: (x3, y3) -> (x4, y4)
    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (denom == 0)
        return false; // Lines are parallel or coincident

    double px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denom;
    double py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denom;

    // Check if the intersection point lies on both segments
    if (px < min(x1, x2) || px > max(x1, x2) || px < min(x3, x4) || px > max(x3, x4) ||
        py < min(y1, y2) || py > max(y1, y2) || py < min(y3, y4) || py > max(y3, y4))
        return false;

    intersection = {px, py};
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++)
    {
        vector<int> p(4);
        for (int j = 0; j < 4; j++)
        {
            cin >> p[j];
        }
        points.push_back(p);
    }

    vector<pair<double, double>> pointsOfInter;

    // Check all pairs of line segments for intersection
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<double, double> intersection;
            if (getIntersection(points[i][0], points[i][1], points[i][2], points[i][3],
                                points[j][0], points[j][1], points[j][2], points[j][3], intersection))
            {
                pointsOfInter.push_back(intersection);
            }
        }
    }

    vector<Point> hullPoints;
    for (auto &p : pointsOfInter)
    {
        hullPoints.push_back({p.first, p.second});
    }

    // Compute the convex hull from intersection points
    vector<Point> convexHullPoints = convexHull(hullPoints);

    // If there are less than 3 points in the convex hull, the area is zero
    if (convexHullPoints.size() < 3)
    {
        cout << 0 << endl;
        return 0;
    }

    // Calculate the area of the polygon formed by the convex hull
    double area = polygonArea(convexHullPoints);

    // Output the maximum area of the polygon as an integer (rounded)
    cout << static_cast<int>(area) << endl;

    return 0;
}
