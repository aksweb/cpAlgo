#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> recStack;

bool dfs(int src)
{
    vis[src] = true;
    recStack[src] = true;

    for (auto v : adj[src])
    {
        if (!vis[v])
        {
            if (dfs(v))
                return true;
        }
        else if (recStack[v])
        {
            return true;
        }
    }

    recStack[src] = false;
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
    recStack.resize(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
    {
        cout << "NO" << endl;
    }
    else
    {
        // Check if any vertex is unvisited (disconnected component)
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }

    return 0;
}
