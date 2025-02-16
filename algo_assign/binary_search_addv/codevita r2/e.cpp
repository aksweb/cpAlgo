#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>

using namespace std;

struct State
{
    int x, y, steps;
};

// Check if a cell is within the matrix bounds
bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Simulate gravity to find the stable cell below a given position
int applyGravity(int x, int y, const vector<vector<char>> &matrix)
{
    while (x + 1 < matrix.size() && matrix[x + 1][y] != 'B')
    {
        x++;
    }
    return x;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    pair<int, int> start;

    // Input matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'S')
            {
                start = {i, j};
            }
        }
    }

    int k;
    cin >> k;

    queue<State> q;
    q.push({start.first, start.second, 0});

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;

    map<int, vector<pair<int, int>>> farthestCells;

    while (!q.empty())
    {
        State current = q.front();
        q.pop();

        int x = current.x, y = current.y, steps = current.steps;

        // Apply gravity
        x = applyGravity(x, y, matrix);

        // Mark as visited
        if (visited[x][y])
            continue;
        visited[x][y] = true;

        // Check if stable and not in the last row
        if (x < n - 1 && matrix[x][y] == 'E')
        {
            int manhattanDist = abs(x - start.first) + abs(y - start.second);
            if (steps <= k)
            {
                farthestCells[manhattanDist].push_back({x, y});
            }
        }

        // Explore neighbors (left, right, up)
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}};
        for (auto dir : directions)
        {
            int dx = dir.first;
            int dy = dir.second;
            int nx = x + dx, ny = y + dy;
            if (isValid(nx, ny, n, m) && !visited[nx][ny] && matrix[nx][ny] != 'B')
            {
                q.push({nx, ny, steps + 1});
            }
        }

        // Move upward if on a building
        if (matrix[x][y] == 'B' && x > 0)
        {
            q.push({x - 1, y, steps + 1});
        }
    }

    // Find the farthest stable cells
    if (!farthestCells.empty())
    {
        auto it = farthestCells.rbegin();
        for (auto &cell : it->second)
        {
            cout << cell.first << " " << cell.second << endl;
        }
    }

    return 0;
}
