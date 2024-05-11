#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};
int ans = 0;
int dfs(vector<vector<int>> &arr, int x, int y, vector<vector<int>> &visited)
{

    visited[x][y] = 1;
    int res = 1;
    for (int i = 0; i < 4; i++)
    {
        int nr = x + dr[i];
        int nc = y + dc[i];

        if (nr < 0 || nc < 0 || nr >= arr.size() || nc >= arr[0].size() || arr[nr][nc] == 0 || visited[nr][nc] == 1)
            continue;

        res += dfs(arr, nr, nc, visited);
    }

    return res;
}
signed main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (visited[i][j] == 0 && arr[i][j] == 1)
            {
                ans = max(dfs(arr, i, j, visited), ans);
            }
    }

    cout << ans << endl;

    return 0;
}