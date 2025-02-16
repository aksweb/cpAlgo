#include <bits/stdc++.h>
using namespace std;

// Function to check if two lines intersect and find the intersection point
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

    vector<pair<double, double>> ans; // Array to store all intersection points

    // Check all pairs of line segments for intersection
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<double, double> intersection;
            if (getIntersection(points[i][0], points[i][1], points[i][2], points[i][3],
                                points[j][0], points[j][1], points[j][2], points[j][3], intersection))
            {
                ans.push_back(intersection);
            }
        }
    }

    // Output all intersection points
    for (auto &p : ans)
    {
        cout << fixed << setprecision(6) << p.first << " " << p.second << endl;
    }

    return 0;
}
