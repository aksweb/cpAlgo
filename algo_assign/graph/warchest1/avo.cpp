#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &adj, int src, int dest)
{
    int n = adj.size();

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n);

    q.push(src);
    used[src] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
        if (used[dest])
            return d[dest];
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> avoid(n);
    vector<vector<int>> adj(n);

    int src, dest;
    cin >> src >> dest;

    for (int &x : avoid)
        cin >> x;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (avoid[u] or avoid[v])
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(adj, src, dest) << endl;
    return 0;
}