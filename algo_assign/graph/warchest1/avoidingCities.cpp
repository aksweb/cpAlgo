#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, m, n) for (int i = m; i < n; i++)
const ll mod = 1e9 + 7;

int solveByBfs(vector<vector<int>> &adj, int src, int dest)
{
    int n = adj.size();
    // cout << "called";
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> d(n, 0);
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // cout << "start";
        for (int x : adj[node])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
                d[x] = d[node] + 1;
            }
        }
        if (vis[dest])
        {
            // cout << "yas rndi" br;
            return d[dest];
        }
        // cout << "in while";
    }
    // cout << "khatam" br;
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int src, dest;
    cin >> src >> dest;
    vector<vector<int>> adj(n);
    vector<int> avoid(n);
    rep(i, 0, n) cin >> avoid[i];
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        if (avoid[x] or avoid[y])
            continue;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    // cout << "calling" br;
    cout << solveByBfs(adj, src, dest);
    // cout << "called" br;
    return 0;
}