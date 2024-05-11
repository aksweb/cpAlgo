#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

bool dfs(int src, int par)
{
    vis[src] = true;
    for (auto v : adj[src])
    {
        if (!vis[v])
        {
            if (dfs(v, src))
                return true;
        }
        else if (par != v)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    vis.resize(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}