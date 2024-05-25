#include <bits/stdc++.h>
using namespace std;
#define br << endl
#define rep(i, m, n) for (int i = m; i < n; i++)
#define pb push_back

int mbfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    int m = adj[0].size();
    int mx = adj[0][0];
    rep(i, 0, n)
    {
        rep(j, 0, m) mx = max(mx, adj[i][j]);
    }
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1)); // Corrected the initialization of dist
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            if (adj[i][j] == mx)
            {
                q.push({i, j});
                dist[i][j] = 0; // Corrected typo from dis to dist
            }
        }
    }
    vector<pair<int, int>> drxn = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    while (!q.empty())
    {
        auto data = q.front();
        q.pop();
        int i = data.first;
        int j = data.second;
        rep(k, 0, 8)
        {
            int ni = i + drxn[k].first;
            int nj = j + drxn[k].second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && dist[ni][nj] == -1)
            {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    // Assuming we want the maximum distance from any source to any cell
    int max_dist = 0;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            max_dist = max(max_dist, dist[i][j]);
        }
    }
    return max_dist;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(m)); // Corrected initialization
        rep(i, 0, n) rep(j, 0, m) cin >> adj[i][j];

        cout << mbfs(adj) br;
    }
    return 0;
}
