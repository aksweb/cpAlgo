#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> bfs(vector<vector<int>> &grid, vector<pii> &init)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pii> q;
    vector<vector<int>> vis(n, vector<int>(m));
    for (pii p : init)
        q.push(p);
    while (q.size())
    {
        pii p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m)
            {
                if (!vis[nx][ny])
                {
                    // checking edge
                    if ((x < 0 or y < 0 or x >= n or y >= m) or

                        (grid[x][y] <= grid[nx][ny]))
                    {

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    return vis;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<pii> ocean1;
    for (int i = -1; i <= m; ++i)
        ocean1.push_back({-1, i});
    for (int i = 0; i < n; ++i)
        ocean1.push_back({i, -1});
    auto vis1 = bfs(heights, ocean1);
    vector<pii> ocean2;
    for (int i = -1; i <= m; ++i)
        ocean2.push_back({n, i});
    for (int i = 0; i < n; ++i)
        ocean2.push_back({i, m});
    auto vis2 = bfs(heights, ocean2);
    vector<vector<int>> ret;
    auto visand = vis1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            visand[i][j] &= vis2[i][j];
        }
    }
    return visand;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> heights[i][j];
        }
    }
    auto ret = pacificAtlantic(heights);

    for (
        int i = 0; i < n; ++i)
    {

        for (int j = 0; j < m; ++j)
        {
            cout << ret[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}