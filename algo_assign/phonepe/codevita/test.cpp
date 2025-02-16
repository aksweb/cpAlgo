#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Struct to represent a point
struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Function to compute the area of a polygon using the shoelace theorem
double shoelaceArea(const std::vector<Point> &polygon)
{
    double area = 0;
    int n = polygon.size();

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n; // next point index (circular)
        area += (polygon[i].x * polygon[j].y) - (polygon[j].x * polygon[i].y);
    }

    return std::abs(area) / 2.0;
}

// Function to check if a set of points are non-collinear
bool isCollinear(const Point &p1, const Point &p2, const Point &p3)
{
    return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0;
}

// Function to generate all subsets of points and compute the area
void findAllAreas(const std::vector<Point> &points)
{
    int n = points.size();
    std::vector<double> areas;

    // Generate all subsets of points
    for (int mask = 1; mask < (1 << n); mask++)
    {
        std::vector<Point> polygon;

        // Collect points corresponding to the set bits in mask
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                polygon.push_back(points[i]);
            }
        }

        // Skip subsets with less than 3 points
        if (polygon.size() < 3)
            continue;

        // Check if the points are non-collinear
        bool collinear = false;
        for (int i = 0; i < polygon.size() - 2; i++)
        {
            if (isCollinear(polygon[i], polygon[i + 1], polygon[i + 2]))
            {
                collinear = true;
                break;
            }
        }

        if (!collinear)
        {
            // Calculate the area of the polygon
            double area = shoelaceArea(polygon);
            areas.push_back(area);
        }
    }

    // Output the unique areas
    std::sort(areas.begin(), areas.end());
    areas.erase(std::unique(areas.begin(), areas.end()), areas.end());

    std::cout << "Possible Areas of polygons formed by the points:" << std::endl;
    for (double area : areas)
    {
        std::cout << area << std::endl;
    }
}

int main()
{
    // Example points
    std::vector<Point> points = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        {2, 2}};

    findAllAreas(points);
    return 0;
}
