// ABHISHEKH786
// ΣDAY
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define ll long long int
#define br << endl
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, n) for (ll i = 1; i <= n; i++)
#define repii(i, n) for (ll i = 1; i < n; i++)
#define gcd __gcd
const ll MOD = 1e9 + 7;

// q r k l
// const
// tc
// isse achha approach nhi melega bhai.

// Code
vector<vector<int>> adj;
int maxDist = -1;

int bfs(int src, vector<vector<int>> &adj)
{
    queue<pair<int, int>> q;
    int n = adj.size();
    vector<bool> vis(n + 1, false);
    int fartNode = src;
    q.push({src, 0});
    vis[src] = true;
    while (!q.empty())
    {
        int dist = q.front().second;
        int node = q.front().first;
        // cout << " dist: " << dist << " "
        //      << " node: " << node br;
        if (dist > maxDist)
        {
            maxDist = dist;
            fartNode = node;
        }
        q.pop();
        for (auto near : adj[node])
        {
            if (!vis[near])
            {
                q.push({near, dist + 1});
                vis[near] = true;
            }
        }
    }
    // cout << "max: " << maxDist br;
    return fartNode;
}

int dia(vector<vector<int>> adj)
{
    int node1 = bfs(1, adj);
    int node2 = bfs(node1, adj);
    return maxDist;
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);

    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cout << dia(adj);

    return 0;
}
